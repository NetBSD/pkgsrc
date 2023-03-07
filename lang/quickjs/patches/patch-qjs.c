$NetBSD: patch-qjs.c,v 1.2 2023/03/07 14:38:03 he Exp $

Portability patch for NetBSD.

--- qjs.c.orig	2019-10-27 10:55:35.000000000 +0000
+++ qjs.c
@@ -146,7 +146,7 @@ static inline size_t js_trace_malloc_usa
     return malloc_size(ptr);
 #elif defined(_WIN32)
     return _msize(ptr);
-#elif defined(EMSCRIPTEN)
+#elif defined(EMSCRIPTEN) || defined(__NetBSD__)
     return 0;
 #elif defined(__linux__)
     return malloc_usable_size(ptr);
@@ -268,7 +268,7 @@ static const JSMallocFunctions trace_mf 
     malloc_size,
 #elif defined(_WIN32)
     (size_t (*)(const void *))_msize,
-#elif defined(EMSCRIPTEN)
+#elif defined(EMSCRIPTEN) || defined(__NetBSD__)
     NULL,
 #elif defined(__linux__)
     (size_t (*)(const void *))malloc_usable_size,
@@ -454,8 +454,10 @@ int main(int argc, char **argv)
         }
     }
 
+#ifdef CONFIG_BIGNUM
     if (load_jscalc)
         bignum_ext = 1;
+#endif
 
     if (trace_memory) {
         js_trace_malloc_init(&trace_data);
