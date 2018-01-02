$NetBSD: patch-src_kmk_kmkbuiltin_osdep.c,v 1.2 2018/01/02 10:37:29 wiz Exp $

Add NetBSD support.

--- src/kmk/kmkbuiltin/osdep.c.orig	2017-11-26 23:29:40.350768372 +0900
+++ src/kmk/kmkbuiltin/osdep.c	2017-12-02 00:41:40.030220196 +0900
@@ -41,8 +41,10 @@
 #elif defined(__OpenBSD__)
 # include "openbsd.c"
 
+#elif defined(__NetBSD__)
+# include <util.h>
+
 #elif defined(__HAIKU__)
 # include "haikufakes.c"
 
 #endif
-
