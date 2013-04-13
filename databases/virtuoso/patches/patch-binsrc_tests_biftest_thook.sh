$NetBSD: patch-binsrc_tests_biftest_thook.sh,v 1.1 2013/04/13 13:16:02 jaapb Exp $

Refer to correct instance of isql
--- binsrc/tests/biftest/thook.sh.orig	2012-03-23 12:28:25.000000000 +0000
+++ binsrc/tests/biftest/thook.sh
@@ -22,7 +22,8 @@
 #
 
 OUTPUT=thook.output
-ISQL=../isql
+ISQL=${ISQL-isql}
+ISQL=../${ISQL}
 TIMEOUT=1000
 HOST_OS=`uname -s | grep WIN`
 SERVER=./virtuoso-iodbc-sample-t
