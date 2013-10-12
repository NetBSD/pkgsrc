$NetBSD: patch-cgen_testsuite_run-tests.sh,v 1.1 2013/10/12 08:39:03 ryoon Exp $

--- cgen/testsuite/run-tests.sh.orig	2009-08-06 16:40:44.000000000 +0000
+++ cgen/testsuite/run-tests.sh
@@ -6,7 +6,7 @@
 
 # The names of tests to run, or ""/"all".
 test_list="$@"
-[ "$test_list" == "" ] && test_list=all
+[ "$test_list" = "" ] && test_list=all
 
 test="driver"
 source ./test-utils.sh
@@ -39,7 +39,7 @@ echo "Test summary:"
 echo "# failures: ${fail_count}"
 echo "# passes:   ${pass_count}"
 
-if [ ${fail_count} == 0 ]
+if [ ${fail_count} = 0 ]
 then
     exit 0
 else
