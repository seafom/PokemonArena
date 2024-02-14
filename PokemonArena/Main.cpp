#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int Hurt(int PokemonLife, int Aattack) {
    if (Aattack == 0) {
        PokemonLife -= 20;
    }
    else if (Aattack == 1) {
        PokemonLife -= 14;
    }
    else if (Aattack == 2) {
        PokemonLife -= 36;
    }
    else if (Aattack == 3) {
        PokemonLife -= 10;
    }
    return PokemonLife;
}

int Damage(int PokemonLife, int Pattack) {
    if (Pattack == 0) {
        PokemonLife -= 20;
    }
    else if (Pattack == 1) {
        PokemonLife -= 14;
    }
    else if (Pattack == 2) {
        PokemonLife -= 36;
    }
    else if (Pattack == 3) {
        PokemonLife -= 10;
    }
    return PokemonLife;
}

int main()
{
    // Random Number Generator
    srand(static_cast<unsigned int>(time(0)));
    int SnorlaxLife = 120; 
    int CharmanderLife = 92;  
    string trainer;

    cout << "==============================\n" << endl;
    cout << "Welcome to Pokemon Battle\n" << endl;
    cout << "==============================\n" << endl;

    cout << "What's your name ?\n" << endl;
    cin >> trainer;
    cout << "Welcome, " << trainer << "!" << endl;
    cout << "A Pokemon appears !" << endl;
    cout << endl;

    cout << "Snorlax, You can do it !" << endl;  

    do {
        cout << "Choose an attack :" << endl;
        cout << "0. BodySlam\n1. Lick\n2. HyperBeam\n3. Lick" << endl;
        int playerAttack;
        cin >> playerAttack;

        CharmanderLife = Damage(CharmanderLife, playerAttack);  
        cout << "Charmander's remaining life: " << CharmanderLife << endl;

        if (CharmanderLife <= 0) {
            cout << "Charmander fainted! " << trainer << " wins, congratulations !" << endl;
            break;
        }

        cout << "Charmander uses a move!" << endl;
        int enemyAttack = rand() % 4;
        SnorlaxLife = Hurt(SnorlaxLife, enemyAttack);  
        cout << "Snorlax's remaining life: " << SnorlaxLife << endl;

        if (SnorlaxLife <= 0) {
            cout << "Snorlax fainted ! " << trainer << " loses, that's a shame..." << endl;
            break;
        }

    } while (CharmanderLife > 0 && SnorlaxLife > 0);

    return 0;
}