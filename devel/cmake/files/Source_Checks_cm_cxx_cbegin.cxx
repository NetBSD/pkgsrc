#include <iterator>
int main()
{
  int a[] = { 0, 1, 2 };
  auto ai = std::cbegin(a);
  return *ai;
}
