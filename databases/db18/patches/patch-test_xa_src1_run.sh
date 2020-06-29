$NetBSD: patch-test_xa_src1_run.sh,v 1.1 2020/06/29 13:30:35 ryoon Exp $

--- test/xa/src1/run.sh.orig	2020-05-29 17:58:22.000000000 +0000
+++ test/xa/src1/run.sh
@@ -4,7 +4,7 @@
 
 msg()
 {
-	test "$DVERBOSE" == 1 && {
+	test "$DVERBOSE" = 1 && {
 		echo "========"
 		echo "======== $1"
 		echo "========"
@@ -29,7 +29,7 @@ cd $RUN/bin
 #
 # For debugging output, add -DDVERBOSE 
 
-test "$DVERBOSE" == 1 && {
+test "$DVERBOSE" = 1 && {
 	COMPILE_FLAGS="-DDVERBOSE"
 	DVERBOSE_FLAG="-v"
 }
