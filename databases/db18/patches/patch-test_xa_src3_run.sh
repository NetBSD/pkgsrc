$NetBSD: patch-test_xa_src3_run.sh,v 1.1 2020/06/29 13:30:35 ryoon Exp $

--- test/xa/src3/run.sh.orig	2020-05-29 17:58:22.000000000 +0000
+++ test/xa/src3/run.sh
@@ -4,7 +4,7 @@
 
 msg()
 {
-	test "$DVERBOSE" == 1 && {
+	test "$DVERBOSE" = 1 && {
 		echo "========"
 		echo "======== $1"
 		echo "========"
@@ -28,7 +28,7 @@ cd $RUN/bin
 #
 # For debugging output, add -DDVERBOSE 
 
-test "$DVERBOSE" == 1 && {
+test "$DVERBOSE" = 1 && {
 	COMPILE_FLAGS="-DDVERBOSE"
 	DVERBOSE_FLAG="-v"
 }
@@ -90,7 +90,7 @@ msg "BOOTING TUXEDO."
 tmboot -y
 
 exitval=0
-if [ $1 == 1 ]; then 
+if [ $1 = 1 ]; then 
         # Create 3 clients, one which kills the server
         ./client -dk $DVERBOSE_FLAG >>2 client_err &
 	./client -d $DVERBOSE_FLAG >>2 client_err &
@@ -115,7 +115,7 @@ echo "STDOUT:"
 cat stdout  
 
 # Killing a server can result in expected database "run recovery" errors
-if [ $1 == 1 ]; then 
+if [ $1 = 1 ]; then 
         exit $exitval
 fi
 
