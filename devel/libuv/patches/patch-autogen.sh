$NetBSD: patch-autogen.sh,v 1.1 2015/06/11 13:32:35 fhajny Exp $

Use libtoolize on Darwin instead of glibtoolize

--- autogen.sh.orig	2015-06-05 17:45:58.000000000 +0000
+++ autogen.sh
@@ -16,10 +16,6 @@
 
 cd `dirname "$0"`
 
-if [ "$LIBTOOLIZE" = "" ] && [ "`uname`" = "Darwin" ]; then
-  LIBTOOLIZE=glibtoolize
-fi
-
 ACLOCAL=${ACLOCAL:-aclocal}
 AUTOCONF=${AUTOCONF:-autoconf}
 AUTOMAKE=${AUTOMAKE:-automake}
