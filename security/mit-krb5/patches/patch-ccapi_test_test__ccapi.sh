$NetBSD: patch-ccapi_test_test__ccapi.sh,v 1.2 2020/10/08 00:23:14 gdt Exp $

Remediate bashism.
Remediate lack of final newline (by accident, but it should be there).

Reported upstream via krb5-bugs@mit.edu on20201007.

--- ccapi/test/test_ccapi.sh.orig	2020-02-12 17:21:58.000000000 +0000
+++ ccapi/test/test_ccapi.sh
@@ -6,7 +6,7 @@ TEST_DIR="tests"
 failure_count=0
 
 function run_test {
-	if [[ -e $TEST_DIR/$1 ]]; then
+	if [ -e "$TEST_DIR/$1" ]; then
 		./$TEST_DIR/$1
 		failure_count=`expr $failure_count + $?`
 	fi
@@ -73,4 +73,4 @@ run_test test_cc_get_NC_info
 
 printf "\nFinished testing CCAPI. $failure_count failures in total.\n"
 
-exit 0
\ No newline at end of file
+exit 0
