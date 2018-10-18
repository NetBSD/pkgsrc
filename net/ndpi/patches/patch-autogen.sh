$NetBSD: patch-autogen.sh,v 1.1 2018/10/18 16:24:29 adam Exp $

Do not remove src/lib/Makefile.in.
Do not lauch 'configure'.

--- autogen.sh.orig	2018-08-22 06:29:35.000000000 +0000
+++ autogen.sh
@@ -5,7 +5,7 @@ NDPI_MINOR="4"
 NDPI_PATCH="0"
 NDPI_VERSION_SHORT="$NDPI_MAJOR.$NDPI_MINOR.$NDPI_PATCH"
 
-rm -f configure config.h config.h.in src/lib/Makefile.in
+rm -f configure config.h config.h.in
 
 AUTOCONF=$(command -v autoconf)
 AUTOMAKE=$(command -v automake)
@@ -45,4 +45,3 @@ cat configure | sed "s/#define PACKAGE/#
 cat configure.tmp > configure
 
 chmod +x configure
-./configure $*
