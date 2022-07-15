$NetBSD: patch-autogen.sh,v 1.2 2022/07/15 13:16:36 adam Exp $

Portability fix.
Use libtoolize on Darwin instead of glibtoolize

--- autogen.sh.orig	2022-07-12 16:16:33.000000000 +0000
+++ autogen.sh
@@ -17,15 +17,12 @@
 set -eu
 cd `dirname "$0"`
 
-if [ "${1:-dev}" == "release" ]; then
+if [ "${1:-dev}" = "release" ]; then
     export LIBUV_RELEASE=true
 else
     export LIBUV_RELEASE=false
 fi
 
-if [ "${LIBTOOLIZE:-}" = "" ] && [ "`uname`" = "Darwin" ]; then
-  LIBTOOLIZE=glibtoolize
-fi
 
 ACLOCAL=${ACLOCAL:-aclocal}
 AUTOCONF=${AUTOCONF:-autoconf}
