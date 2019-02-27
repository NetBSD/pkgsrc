#include <iterator>
int main()
{
  int a[] = { 2, 1, 0 };
  auto ai = std::cend(a);
  return *(ai - 1);
}
