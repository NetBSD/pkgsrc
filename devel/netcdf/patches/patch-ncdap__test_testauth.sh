$NetBSD: patch-ncdap__test_testauth.sh,v 1.1 2017/11/28 17:52:02 minskim Exp $

Portability fix.

--- ncdap_test/testauth.sh.orig	2016-11-21 19:43:03.000000000 +0000
+++ ncdap_test/testauth.sh
@@ -273,7 +273,7 @@ if test "x$RCHOME" = x1 ; then
   show
 fi
 
-if test "x$RCSPEC" == x1 ; then
+if test "x$RCSPEC" = x1 ; then
   echo "*** Testing rc file in specified directory"
   # Create the rc file and (optional) netrc file
   xf; reset; xo
@@ -324,4 +324,3 @@ restore
 xo
 
 exit
-
