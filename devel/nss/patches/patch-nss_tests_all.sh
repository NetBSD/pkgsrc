$NetBSD: patch-nss_tests_all.sh,v 1.2 2019/09/06 02:54:47 ryoon Exp $

Revert Bug 1377940 to fix misc/libreoffice

--- nss/tests/all.sh.orig	2019-08-30 15:46:32.000000000 +0000
+++ nss/tests/all.sh
@@ -114,8 +114,6 @@ RUN_FIPS=""
 ########################################################################
 run_tests()
 {
-    echo "Running test cycle: ${TEST_MODE} ----------------------"
-    echo "List of tests that will be executed: ${TESTS}"
     for TEST in ${TESTS}
     do
         # NOTE: the spaces are important. If you don't include
@@ -173,9 +171,8 @@ run_cycle_pkix()
 
     export -n NSS_SSL_RUN
 
-    # use the default format. (unset for the shell, export -n for binaries)
+    # use the default format
     export -n NSS_DEFAULT_DB_TYPE
-    unset NSS_DEFAULT_DB_TYPE
 
     run_tests
 }
