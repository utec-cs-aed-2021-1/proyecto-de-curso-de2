#include <iostream>

using namespace std;

void algoritmoPrim () {
    if (pri != NULL){
        actualizarCampos();
        cout << "Digite el vertice inicial: ";
        cin >> auxNod;
        ban = 0;
        while (ban == 0){
            aux = pri;
            while (aux != NULL){
                if (aux->nod == auxNod){
                    ban = 1;
                }
                aux = aux->sig;
            }
            if (ban == 0){
                cout << "\nNo existe un nodo con esa letra.";
                aux = pri;
                cout << "\n---Lista de Nodos---\n";
                while (aux != NULL){
                    cout << aux->nod << " ";
                    aux = aux->sig;
                }
                cout << "\nDigite uno de los anteriores nodos: ";
                cin >> auxNod;
            }
        }
        aux = pri;
        while (aux->nod != auxNod){
            aux = aux->sig;
        }
        aux->marca = 1;
        auxArc = aux->arc;
        while (auxArc != NULL){
            auxArc->marca = 1;
            auxArc = auxArc->sig;
        }
        cout << "\nSe han marcado todos los arcos para el vertice elegido.";
        ban2 = 1;
        while (ban2 == 1){
            paso2();
            ban2 = 0;
            aux = pri;
            while (aux != NULL){
                if (aux->marca == 0){
                    ban2 = 1;
                }
                aux = aux->sig;
            }
        }
        listarAdyacenciaPrim ();
        sumaCaminos();
    }
    getch();
}