$NetBSD: patch-autogen.sh,v 1.3 2023/05/19 20:35:47 adam Exp $

On Darwin, use libtoolize instead of glibtoolize

--- autogen.sh.orig	2023-05-19 11:21:01.000000000 +0000
+++ autogen.sh
@@ -23,9 +23,6 @@ else
     export LIBUV_RELEASE=false
 fi
 
-if [ "${LIBTOOLIZE:-}" = "" ] && [ "`uname`" = "Darwin" ]; then
-  LIBTOOLIZE=glibtoolize
-fi
 
 ACLOCAL=${ACLOCAL:-aclocal}
 AUTOCONF=${AUTOCONF:-autoconf}
