#include <iostream>
#include <time.h>
#include <iomanip>
#include <Windows.h>

using namespace std;

void Create(int* a, const int size, const int low, const int high)
{
	for (int i = 0; i < size; i++)
		a[i] = low + rand() % (high - low + 1);
}

void Print(int* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(5) << a[i];
	cout << endl;
}

int PosEl(int* a, int n)//Кількість додатних елементів масиву.
{
	int p = 0;
	for (int i = 0; i < n; i++)

		if (a[i] > 0)
			p++;
	return p;
}

int Sum(int* a, const int size)//Суму елементів  розташованих після нуля
{
	int S = 0;
	for (int i = 0; i < size; i++)
		if (a[i] == 0)
			for (a[i]; i < size; i++)
			S += a[i];
	return S;
}

void Sort(int* a, const int size)//спочатку розташовувалися всі елементи, ціла частина яких не перевищує одиниці, а потім – всі інші
{
	for (int i = 1; i < size; i++)
	{

		for (int j = 0; j < size - i; j++)
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;

			}

	}
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
    srand((unsigned)time(NULL));
    
	int n;
	cout << "  Кількість елементів - "; cin >> n;
	int* a = new int[n];
	int low = -100;
	int high = 120;

	Create(a, n, low, high);
	cout << "  Ваш масив" << endl;
	Print(a, n);
	cout << "  Модифікований масив " << endl;
	Sort(a, n);
	Print(a, n);

	cout << "  Додатні елементи - " << PosEl(a, n) << endl;
	cout << "  Сума -  " << Sum(a, n) << endl;
	
	return 0;
}