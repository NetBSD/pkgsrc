$NetBSD: patch-ncdap__test_testauth.sh,v 1.2 2018/05/16 06:32:58 wen Exp $

Portability fix.

--- ncdap_test/testauth.sh.orig	2018-05-16 03:08:45.000000000 +0000
+++ ncdap_test/testauth.sh
@@ -246,7 +246,7 @@ if test "x$RCHOME" = x1 ; then
   show
 fi
 
-if test "x$RCSPEC" == x1 ; then
+if test "x$RCSPEC" = x1 ; then
   echo "*** Testing rc file in specified directory"
   # Create the rc file and (optional) netrc file
   reset
