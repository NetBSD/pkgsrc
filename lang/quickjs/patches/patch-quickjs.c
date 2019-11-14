$NetBSD: patch-quickjs.c,v 1.1 2019/11/14 21:20:04 rillig Exp $

Portability patch for NetBSD.

--- quickjs.c.orig	2019-10-27 10:55:35.000000000 +0000
+++ quickjs.c
@@ -1343,7 +1343,7 @@ static inline size_t js_def_malloc_usabl
     return malloc_size(ptr);
 #elif defined(_WIN32)
     return _msize(ptr);
-#elif defined(EMSCRIPTEN)
+#elif defined(EMSCRIPTEN) || defined(__NetBSD__)
     return 0;
 #elif defined(__linux__)
     return malloc_usable_size(ptr);
@@ -1417,7 +1417,7 @@ static const JSMallocFunctions def_mallo
     malloc_size,
 #elif defined(_WIN32)
     (size_t (*)(const void *))_msize,
-#elif defined(EMSCRIPTEN)
+#elif defined(EMSCRIPTEN) || defined(__NetBSD__)
     NULL,
 #elif defined(__linux__)
     (size_t (*)(const void *))malloc_usable_size,
