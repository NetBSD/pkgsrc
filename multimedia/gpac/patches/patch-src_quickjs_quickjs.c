$NetBSD: patch-src_quickjs_quickjs.c,v 1.1 2021/09/17 00:10:21 nia Exp $

Add support for NetBSD.

--- src/quickjs/quickjs.c.orig	2020-09-10 16:38:49.000000000 +0000
+++ src/quickjs/quickjs.c
@@ -36,7 +36,7 @@
 #include <math.h>
 #if defined(__APPLE__)
 #include <malloc/malloc.h>
-#elif defined(__linux__) || defined(__NX__)
+#elif defined(__linux__) || defined(__NX__) || defined(__NetBSD__)
 #include <malloc.h>
 #endif
 
