$NetBSD: patch-symfony_lib_vendor_google_apiclient-services_generator_run__tests.sh,v 1.1 2022/05/05 11:38:09 mef Exp $

ERROR: [check-portability.awk] symfony/lib/vendor/google/apiclient-services/generator/run_tests.sh:25:   if [ $? == 0 ]; then

--- symfony/lib/vendor/google/apiclient-services/generator/run_tests.sh.orig	2022-03-23 13:53:28.000000000 +0900
+++ symfony/lib/vendor/google/apiclient-services/generator/run_tests.sh	2022-05-05 20:27:42.340500900 +0900
@@ -22,7 +22,7 @@ cd $TOP/tests
 find . -name '*_test.py' | while read test
 do
   python $test
-  if [ $? == 0 ]; then
+  if [ $? = 0 ]; then
     echo "${test}" >> "${SUCCEEDED_FILE}"
   else
     echo "${test}" >> "${FAILED_FILE}"
