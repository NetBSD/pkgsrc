$NetBSD: patch-tests_run__tests.sh,v 1.1 2020/04/21 13:56:26 nia Exp $

Shell portability.

--- tests/run_tests.sh.orig	2007-11-20 19:27:57.000000000 +0000
+++ tests/run_tests.sh
@@ -6,7 +6,7 @@ failed=0
 for i in *_unittest; do
   echo -n "$i... "
   `./$i > /dev/null 2>&1`
-  if [ $? == 0 ]; then
+  if [ $? = 0 ]; then
     echo "PASS"
   else
     echo "FAILED"
