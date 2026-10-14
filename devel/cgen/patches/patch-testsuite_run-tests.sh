$NetBSD: patch-testsuite_run-tests.sh,v 1.1 2026/10/14 15:02:46 ryoon Exp $

* POSIX shell portability.

--- testsuite/run-tests.sh.orig	2026-10-14 06:54:55.207116968 +0000
+++ testsuite/run-tests.sh
@@ -6,7 +6,7 @@ test_list="$@"
 
 # The names of tests to run, or ""/"all".
 test_list="$@"
-[ "$test_list" == "" ] && test_list=all
+[ "$test_list" = "" ] && test_list=all
 
 test="driver"
 source ./test-utils.sh
@@ -39,7 +39,7 @@ echo "# passes:   ${pass_count}"
 echo "# failures: ${fail_count}"
 echo "# passes:   ${pass_count}"
 
-if [ ${fail_count} == 0 ]
+if [ ${fail_count} = 0 ]
 then
     exit 0
 else
