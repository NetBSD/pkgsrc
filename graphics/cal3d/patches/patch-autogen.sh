$NetBSD: patch-autogen.sh,v 1.1 2013/08/17 11:15:26 joerg Exp $

--- autogen.sh.orig	2013-08-16 13:21:36.000000000 +0000
+++ autogen.sh
@@ -41,7 +41,7 @@ echo "Running $AUTOHEADER..."
 $AUTOHEADER
 
 echo "Running $AUTOMAKE ..."
-$AUTOMAKE
+$AUTOMAKE -a
 
 echo "Running $AUTOCONF ..."
 $AUTOCONF
