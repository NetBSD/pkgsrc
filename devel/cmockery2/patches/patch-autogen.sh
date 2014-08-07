$NetBSD: patch-autogen.sh,v 1.1 2014/08/07 11:18:04 manu Exp $

pkgsrc maks a aclocal-1.9 stub available in PATH, and this
breaks the build. Force aclocal usage.

--- autogen.sh.orig	2014-07-22 15:39:39.000000000 +0000
+++ autogen.sh	2014-07-22 15:40:45.000000000 +0000
@@ -30,8 +30,12 @@
 if ! env "$AUTOMAKE" --version > /dev/null 2>&1 ; then
   AUTOMAKE=automake
 fi
 
+# pkgsrc build failur eworkaround
+ACLOCAL=aclocal
+AUTOMAKE=automake
+
 # glibtoolize is used for Mac OS X
 LIBTOOLIZE=libtoolize
 if ! env "$LIBTOOLIZE" --version > /dev/null 2>&1 ; then
   LIBTOOLIZE=glibtoolize
