$NetBSD: patch-quickjs.c,v 1.4 2025/02/07 12:36:24 pho Exp $

Portability patch for NetBSD.

--- quickjs.c.orig	2024-01-13 10:20:39.000000000 +0000
+++ quickjs.c
@@ -68,7 +68,15 @@
 /* define to include Atomics.* operations which depend on the OS
    threads */
 #if !defined(EMSCRIPTEN)
+#ifdef __NetBSD__
+#ifdef __HAVE_ATOMICOPS64_OPS
 #define CONFIG_ATOMICS
+#else
+#undef CONFIG_ATOMICS
+#endif /* __HAVE_ATOMICOPS64_OPS */
+#else /* !__NetBSD__ */
+#define CONFIG_ATOMICS
+#endif /* __NetBSD__ */
 #endif
 
 #if !defined(EMSCRIPTEN)
@@ -1699,7 +1707,7 @@ static size_t js_def_malloc_usable_size(
     return malloc_size(ptr);
 #elif defined(_WIN32)
     return _msize((void *)ptr);
-#elif defined(EMSCRIPTEN)
+#elif defined(EMSCRIPTEN) || defined(__NetBSD__)
     return 0;
 #elif defined(__linux__)
     return malloc_usable_size((void *)ptr);
