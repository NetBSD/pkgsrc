$NetBSD: patch-examples_miniviewer__gl_autogen.sh,v 1.1 2013/08/31 14:49:41 joerg Exp $

--- examples/miniviewer_gl/autogen.sh.orig	2013-08-31 14:30:03.000000000 +0000
+++ examples/miniviewer_gl/autogen.sh
@@ -41,7 +41,7 @@ echo "Running $AUTOHEADER..."
 $AUTOHEADER
 
 echo "Running $AUTOMAKE ..."
-$AUTOMAKE
+$AUTOMAKE -a
 
 echo "Running $AUTOCONF ..."
 $AUTOCONF
