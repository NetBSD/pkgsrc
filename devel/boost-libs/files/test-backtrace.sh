#!/bin/sh

# Given a compiler command, test if libbacktrace is available.
# It is shipped with GCC, sometimes, and not in the official
# places.

set -e

cc=$1; shift
dir=$(mktemp -d "${TMPDIR:-/tmp}/conftest.XXXXXX")
cd "$dir"
cat > test.c <<EOT
#include <backtrace.h>
int main()
{
  return 0;
}
EOT
$cc -o test test.c -lbacktrace 2>/dev/null  &&
echo yes ||
echo no
cd
rm -rf "$dir"
