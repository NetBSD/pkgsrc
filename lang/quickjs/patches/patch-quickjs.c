$NetBSD: patch-quickjs.c,v 1.2 2020/01/26 18:37:49 he Exp $

Portability patch for NetBSD.

--- quickjs.c.orig	2020-01-19 10:12:01.000000000 +0000
+++ quickjs.c
@@ -68,7 +68,15 @@
 /* define to include Atomics.* operations which depend on the OS
    threads */
 #if !defined(EMSCRIPTEN)
+#ifdef __NetBSD__
+#ifdef __HAVE_ATOMICS64_OPS
 #define CONFIG_ATOMICS
+#else
+#undef CONFIG_ATOMICS
+#endif /* __HAVE_ATOMICS64_OPS */
+#else /* ! __NetBSD__ */
+#define CONFIG_ATOMICS
+#endif /* __NetBSD__ */
 #endif
 
 /* dump object free */
@@ -1544,7 +1552,7 @@ static inline size_t js_def_malloc_usabl
     return malloc_size(ptr);
 #elif defined(_WIN32)
     return _msize(ptr);
-#elif defined(EMSCRIPTEN)
+#elif defined(EMSCRIPTEN) || defined(__NetBSD__)
     return 0;
 #elif defined(__linux__)
     return malloc_usable_size(ptr);
@@ -1618,7 +1626,7 @@ static const JSMallocFunctions def_mallo
     malloc_size,
 #elif defined(_WIN32)
     (size_t (*)(const void *))_msize,
-#elif defined(EMSCRIPTEN)
+#elif defined(EMSCRIPTEN) || defined(__NetBSD__)
     NULL,
 #elif defined(__linux__)
     (size_t (*)(const void *))malloc_usable_size,
