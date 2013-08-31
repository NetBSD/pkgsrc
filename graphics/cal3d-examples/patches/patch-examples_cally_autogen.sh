$NetBSD: patch-examples_cally_autogen.sh,v 1.1 2013/08/31 14:49:41 joerg Exp $

--- examples/cally/autogen.sh.orig	2013-08-31 14:30:05.000000000 +0000
+++ examples/cally/autogen.sh
@@ -41,7 +41,7 @@ echo "Running $AUTOHEADER..."
 $AUTOHEADER
 
 echo "Running $AUTOMAKE ..."
-$AUTOMAKE
+$AUTOMAKE -a
 
 echo "Running $AUTOCONF ..."
 $AUTOCONF
