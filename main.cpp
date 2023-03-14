#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <random>
using namespace std;
int currentMoney = 1000;
void meta()
{
	ofstream meta_file("meta.txt", ios_base::out);
	if (meta_file.is_open()) {
		meta_file << currentMoney;
		meta_file.close();
	}
}
void read()
{
	ifstream meta_file("meta.txt", ios_base::in);
	meta_file >> currentMoney;
	meta_file.close();
}
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "");
	read();
	random_device r;
	default_random_engine e(r());
	uniform_int_distribution<int> dist(3, 11);
	uniform_int_distribution<int> befg(2, 12);
	int bet;
	int firstCubes = dist(e);
	int secondCubes = befg(e);
	int x;
	cout << "Текущее состояние: " << currentMoney << endl;
	cout << "Первые кубики: " << firstCubes << endl;
	cout << "Ставка: " << endl;
	cin >> bet;
	if (bet > currentMoney)
	{
		system("cls");
		cout << "Текущее состояние: " << currentMoney << endl;
		cout << "Первые кубики: " << firstCubes << endl;
		cout << "Слишком Большая ставка!" << endl;
		cin >> bet;
	}
	if (bet == 0)
	{
		cout << "Слишком маленькая ставка!" << endl;
		Sleep(1500);
		system("cls");
		main();
	}
	system("cls");
	cout << "Текущее состояние: " << currentMoney << endl;
	cout << "Первые кубики: " << firstCubes << endl;
	cout << "Больше(1) или меньше(2)?" << endl;
	cin >> x;
	system("cls");
	cout << "Первые кубики: " << firstCubes << endl;
	cout << "Вторые кубики: " << secondCubes << endl;
	Sleep(2500);
	if (x == 1 and firstCubes < secondCubes)
	{
		system("cls");
		cout << "Поздравялю вы выйграли " << bet << endl;
		currentMoney += bet;
		meta();
	}
	if (x == 2 and firstCubes > secondCubes)
	{
		system("cls");
		cout << "Поздравялю вы выйграли " << bet << endl;
		currentMoney += bet;
		meta();
	}
	if (x == 1 and firstCubes > secondCubes)
	{
		system("cls");
		cout << "Вы проиграли " << bet << endl;
		currentMoney -= bet;
		meta();
	}
	if (x == 2 and firstCubes < secondCubes)
	{
		system("cls");
		cout << "Вы проиграли " << bet << endl;
		currentMoney -= bet;
		meta();
	}
	if (x == 3)
	{
		exit(0);
	}
	if (firstCubes == secondCubes)
	{
		cout << "Ничья!" << endl;
	}
	if (currentMoney == 0)
	{
		system("cls");
		cout << "Слишком мало денег, баланс обновлен!" << endl;
		currentMoney += 1000;
		Sleep(500);
		meta();
	}
	main();
	return 0;
}
