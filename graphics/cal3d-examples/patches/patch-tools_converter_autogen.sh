$NetBSD: patch-tools_converter_autogen.sh,v 1.1 2013/08/31 14:49:41 joerg Exp $

--- tools/converter/autogen.sh.orig	2013-08-31 14:30:00.000000000 +0000
+++ tools/converter/autogen.sh
@@ -41,7 +41,7 @@ echo "Running $AUTOHEADER..."
 $AUTOHEADER
 
 echo "Running $AUTOMAKE ..."
-$AUTOMAKE
+$AUTOMAKE -a
 
 echo "Running $AUTOCONF ..."
 $AUTOCONF
