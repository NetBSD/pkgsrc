$NetBSD: patch-autogen.sh,v 1.1 2013/08/31 14:49:41 joerg Exp $

--- autogen.sh.orig	2013-08-31 14:23:56.000000000 +0000
+++ autogen.sh
@@ -41,7 +41,7 @@ echo "Running $AUTOHEADER..."
 $AUTOHEADER
 
 echo "Running $AUTOMAKE ..."
-$AUTOMAKE
+$AUTOMAKE -a
 
 echo "Running $AUTOCONF ..."
 $AUTOCONF
