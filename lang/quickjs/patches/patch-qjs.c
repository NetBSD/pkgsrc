$NetBSD: patch-qjs.c,v 1.1 2019/11/14 21:20:04 rillig Exp $

Portability patch for NetBSD.

--- qjs.c.orig	2019-10-27 10:55:35.000000000 +0000
+++ qjs.c
@@ -124,7 +124,7 @@ static inline size_t js_trace_malloc_usa
     return malloc_size(ptr);
 #elif defined(_WIN32)
     return _msize(ptr);
-#elif defined(EMSCRIPTEN)
+#elif defined(EMSCRIPTEN) || defined(__NetBSD__)
     return 0;
 #elif defined(__linux__)
     return malloc_usable_size(ptr);
@@ -240,7 +240,7 @@ static const JSMallocFunctions trace_mf 
     malloc_size,
 #elif defined(_WIN32)
     (size_t (*)(const void *))_msize,
-#elif defined(EMSCRIPTEN)
+#elif defined(EMSCRIPTEN) || defined(__NetBSD__)
     NULL,
 #elif defined(__linux__)
     (size_t (*)(const void *))malloc_usable_size,
