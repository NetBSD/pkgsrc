$NetBSD: patch-src_quickjs_quickjs.c,v 1.2 2025/10/31 21:46:23 adam Exp $

Add support for NetBSD.

--- src/quickjs/quickjs.c.orig	2024-04-17 17:18:21.000000000 +0000
+++ src/quickjs/quickjs.c
@@ -36,7 +36,7 @@
 #include <math.h>
 #if defined(__APPLE__)
 #include <malloc/malloc.h>
-#elif defined(__linux__) || defined(__NX__)
+#elif defined(__linux__) || defined(__NX__) || defined(__NetBSD__)
 #include <malloc.h>
 #elif defined(__FreeBSD__)
 #include <malloc_np.h>
