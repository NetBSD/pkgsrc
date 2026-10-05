$NetBSD: patch-tests_lcov_extract_extract2.sh,v 1.1 2026/10/05 19:39:02 wiz Exp $

NetBSD's mkdir has no -p.
https://github.com/linux-test-project/lcov/issues/553

--- tests/lcov/extract/extract2.sh.orig	2026-10-05 19:11:12.392950154 +0000
+++ tests/lcov/extract/extract2.sh
@@ -761,7 +761,7 @@ rm -rf ./mytest
 
 # test filename containing spaces
 rm -rf ./mytest
-mkdir -pv ./mytest
+mkdir -p ./mytest
 echo "int main(){}" > './mytest/main space.cpp'
 ( cd ./mytest ; ${CXX} -c  'main space.cpp' --coverage )
 
