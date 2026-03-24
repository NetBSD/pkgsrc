#! /bin/sh

set -e

./depgraph.sh -V

echo "1. test basics"
./depgraph.sh clang > 1.out
diff 1.expected 1.out
rm -f 1.out

echo "2. name and version"
./depgraph.sh -v clang > 2.out
diff 2.expected 2.out
rm -f 2.out

echo "3. test everything"
./depgraph.sh > 3.out
diff 3.expected 3.out
rm -f 3.out

echo "4. test everything with versions"
./depgraph.sh -v > 4.out
diff 4.expected 4.out
rm -f 4.out

echo "5. test everything with versions and licenses"
./depgraph.sh -v -l > 5.out
diff 5.expected 5.out
rm -f 5.out

echo "6. test everything with licenses"
./depgraph.sh -l > 6.out
diff 6.expected 6.out
rm -f 6.out

echo "7. license, version numbers and json"
./depgraph.sh -l -v -j | jq . > 7.out
diff 7.expected 7.out
rm -f 7.out

echo "8. package that's not installed"
./depgraph.sh clung EMACS not-there > 8.out
diff 8.expected 8.out
rm -f 8.out
