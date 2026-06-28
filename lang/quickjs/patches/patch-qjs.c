$NetBSD: patch-qjs.c,v 1.5 2026/06/28 17:59:25 osa Exp $

Portability patch for NetBSD.

--- qjs.c.orig	2026-06-04 08:26:08.000000000 -0400
+++ qjs.c	2026-06-28 13:48:19.865553282 -0400
@@ -139,7 +139,7 @@
     return malloc_size(ptr);
 #elif defined(_WIN32)
     return _msize((void *)ptr);
-#elif defined(__EMSCRIPTEN__)
+#elif defined(__EMSCRIPTEN__) || defined(__NetBSD__)
     return 0;
 #elif defined(__linux__) || defined(__GLIBC__)
     return malloc_usable_size((void *)ptr);
