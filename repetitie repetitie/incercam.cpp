#include <iostream>

using namespace std;

class Carte {
	int nrPagini;
	float pret;
	char* titlu;
	string autor;
	bool terminata;

public:
	Carte() {
		this->nrPagini = 300;
		this->pret = 25.50;
		this->titlu = new char[strlen("text") + 1];
		strcpy_s(this->titlu, strlen("text") + 1, "text");
		this->autor = "Jules Vernes";
		this->terminata = false;
	}

	Carte(int altePagini, float pretNou, const char* titluNou)
	{
		this->nrPagini = altePagini;
		this->pret = pretNou;
		this->titlu = new char[strlen(titluNou) + 1];
		strcpy_s(this->titlu, strlen(titluNou) + 1, titluNou);
		this->autor = "Jules Vernes";
		this->terminata = false;

	}


	Carte(const Carte& book)
	{
		this->nrPagini = book.nrPagini;
		this->pret = book.pret;
		this->titlu = new char[strlen(book.titlu) + 1];
		strcpy_s(this->titlu, strlen(book.titlu) + 1, book.titlu);
		this->autor = book.autor;
		this->terminata = book.terminata;
	}

	~Carte() {
		delete[] this->titlu;
	}

	Carte operator=(const Carte& c){
		if (this != &c)
		{
			this->nrPagini = c.nrPagini;
			this->pret = c.pret;
			if (this->titlu != NULL)
				delete[] this->titlu;
			this->titlu = new char[strlen(c.titlu) + 1];
			strcpy_s(this->titlu, strlen(c.titlu) + 1, c.titlu);
			this->autor = c.autor;
			this->terminata = c.terminata;
		}
		return *this;
	}

	Carte operator+(float crestere) const{
		Carte react = *this;
		react.pret = react.pret + crestere;
		return react;
	}

	friend ostream& operator<<(ostream& out, const Carte& c1)
	{
		out << "Titlul cartii: "<< c1.titlu << endl;
		out << "Autorul: "<< c1.autor << endl;
		out << "Numarul de pagini: "<< c1.nrPagini << endl;
		out << "Pretul: "<< c1.pret << endl;
		out << "A fost citita? (0/1): "<< c1.terminata << endl;
		return out;
	}



};

class Cititor {
	friend Carte;
	string nume;
	Carte carte;

public:
	Cititor(string nume, Carte carteCurenta)
	{
		this->nume = nume;
		this->carte = carteCurenta;
	}

	void afisareCititor() {
		cout << "Numele cititorului: " << this->nume << endl; 
		cout << "Cartea lui/ei: " << endl << this->carte << endl;
	}
};

void main()
{
	Carte c1(250, 27.5, "Guliver");
	Carte c2 = c1;
	c2= c2 + 10.5;
	cout << c1 << endl;
	cout << c2 << endl;
	Cititor R("Razvan", c1);
	R.afisareCititor();

}