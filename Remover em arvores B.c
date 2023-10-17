funcao remover(chave, raiz) -> bool
                                                                                            // verificar se a arvore esta vazia ou se a chave nao existe na arvore
  se raiz == nulo ou buscar(chave, raiz) == falso entao
     retornar falso
  fim se
                                                                                                  // verificar se a raiz e uma folha
  se raiz e folha entao
                                                                                                // remover a chave da raiz
    remover chave de raiz
                                                                                                // verificar se ocorreu underflow na folha
    se raiz->n < t entao
                                                                                                    // t e  o grau minimo da arvore B
      retornar underflow
    senao
      retornar verdadeiro
    fim se
  senao // raiz nao e folha
                                                                                                                    // encontrar a posicao i da chave na raiz->chaves[]
    encontrar i tal que raiz->chaves[i-1] < chave <= raiz->chaves[i]

                                                                                                // verificar se a chave esta na raiz
    se i < raiz->n e raiz->chaves[i] == chave entao
                                                                                // trocar a chave com sua sucessora ou predecessora que esta em uma folha
      se raiz->filhos[i+1] tem pelo menos t chaves entao                                                 // filho direito da chave
                                                                    // encontrar a sucessora k da chave em raiz->filhos[i+1]
        k = menor_chave(raiz->filhos[i+1])
                                                                                            // substituir a chave pela sucessora
         raiz->chaves[i] = k
                                                                                            // remover a sucessora recursivamente do filho direito da chave
         remover(k, raiz->filhos[i+1])
      senao se raiz->filhos[i] tem pelo menos t chaves entao                                      // filho esquerdo da chave
                                                                             // encontrar a predecessora k da chave em raiz->filhos[i]
            k = maior_chave(raiz->filhos[i])
                                                                    // substituir a chave pela predecessora
        raiz->chaves[i] = k
                                                                // remover a predecessora recursivamente do filho esquerdo da chave
        remover(k, raiz->filhos[i])
      senao                                                                 // ambos os filhos tem t-1 chaves
                                                                        // concatenar a chave e seus dois filhos em uma pagina
        concatenar(raiz, i)
                                                                        // remover a chave recursivamente da nova pagina
        remover(chave, raiz->filhos[i])
      fim se
    senao   // chave nao esta na raiz, mas em algum subarvore abaixo dela
                                                            // verificar se o filho onde a chave pode estar tem underflow potencial
      se raiz->filhos[i] tem menos que t chaves entao
                                                             // preencher o filho com uma chave do irmao ou do pai
        preencher(raiz, i)
      fim se
                                                             // verificar se o ultimo filho foi concatenado com o anterior
      se i > raiz->n entao
                                                               // remover a chave recursivamente do novo ultimo filho
        remover(chave, raiz->filhos[i-1])
      senao
                                                                        // remover a chave recursivamente do filho adequado
        remover(chave, raiz->filhos[i])
      fim se
    fim se

                                                                   // verificar se ocorreu underflow na raiz
    se raiz->n == 0 entao
      retornar underflow
    senao
      retornar verdadeiro
    fim se
  fim se
fim }
