$NetBSD: patch-nsock_tests_run__tests.sh,v 1.1 2016/01/24 13:46:49 richard Exp $

--- nsock/tests/run_tests.sh.orig	2015-11-10 04:26:26.000000000 +0000
+++ nsock/tests/run_tests.sh
@@ -11,7 +11,7 @@ PORT_TCPSSL=$(grep "PORT_TCPSSL " test-c
 EXEC_MAIN=./tests_main
 
 NCAT=${NCAT:-ncat}
-if [ ! -x "$NCAT" -a -z "$(which $NCAT)" ]; then
+if [ ! -x "$NCAT" ]; then
     echo "Can't find your ncat: $NCAT"
     echo "Trying ../../ncat/ncat"
     NCAT="../../ncat/ncat"
