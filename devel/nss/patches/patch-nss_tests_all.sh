$NetBSD: patch-nss_tests_all.sh,v 1.1 2018/02/24 11:35:48 ryoon Exp $

Revert Bug 1377940 to fix misc/libreoffice

--- nss/tests/all.sh.orig	2018-01-18 14:19:59.000000000 +0000
+++ nss/tests/all.sh
@@ -111,8 +111,6 @@ RUN_FIPS=""
 ########################################################################
 run_tests()
 {
-    echo "Running test cycle: ${TEST_MODE} ----------------------"
-    echo "List of tests that will be executed: ${TESTS}"
     for TEST in ${TESTS}
     do
         # NOTE: the spaces are important. If you don't include
@@ -174,9 +172,8 @@ run_cycle_pkix()
     NSS_SSL_TESTS=`echo "${NSS_SSL_TESTS}" | sed -e "s/normal//g" -e "s/fips//g" -e "s/_//g"`
     export -n NSS_SSL_RUN
 
-    # use the default format. (unset for the shell, export -n for binaries)
+    # use the default format
     export -n NSS_DEFAULT_DB_TYPE
-    unset NSS_DEFAULT_DB_TYPE
 
     run_tests
 }
