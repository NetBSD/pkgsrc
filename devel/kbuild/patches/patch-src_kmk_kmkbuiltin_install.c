$NetBSD: patch-src_kmk_kmkbuiltin_install.c,v 1.1 2016/07/08 09:42:54 kamil Exp $

Add NetBSD support.

--- src/kmk/kmkbuiltin/install.c.orig	2015-06-21 21:21:29.000000000 +0000
+++ src/kmk/kmkbuiltin/install.c
@@ -87,6 +87,9 @@ __FBSDID("$FreeBSD: src/usr.bin/xinstall
 #ifdef __HAIKU__
 # include "haikufakes.h"
 #endif
+#ifdef __NetBSD__
+# include "strtofflags.c"
+#endif
 #include "kmkbuiltin.h"
 
 
@@ -1118,4 +1121,3 @@ last_slash(const char *path)
     return strrchr(path, '/');
 #endif
 }
-
