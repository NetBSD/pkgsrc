$NetBSD: patch-test_xa_src5_run.sh,v 1.1 2020/06/29 13:30:35 ryoon Exp $

--- test/xa/src5/run.sh.orig	2020-05-29 17:58:22.000000000 +0000
+++ test/xa/src5/run.sh
@@ -7,7 +7,7 @@
 
 msg()
 {
-	test "$DVERBOSE" == 1 && {
+	test "$DVERBOSE" = 1 && {
 		echo "========"
 		echo "======== $1"
 		echo "========"
@@ -37,7 +37,7 @@ fi
 #
 # For debugging output, add -DDVERBOSE 
 
-test "$DVERBOSE" == 1 && {
+test "$DVERBOSE" = 1 && {
 	COMPILE_FLAGS="-DDVERBOSE"
 	DVERBOSE_FLAG="-v"
 }
