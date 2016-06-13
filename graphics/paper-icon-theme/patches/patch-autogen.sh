$NetBSD: patch-autogen.sh,v 1.1 2016/06/13 00:26:04 youri Exp $

Do not hardcode /usr.

--- autogen.sh.orig	2016-05-23 02:15:15.000000000 +0000
+++ autogen.sh
@@ -6,6 +6,6 @@ autoreconf --force --install --symlink -
 
 if test -z "${NOCONFIGURE}"; then
     set -x
-    ./configure --prefix=/usr "$@"
+    ./configure "$@"
     make clean
-fi
\ No newline at end of file
+fi
