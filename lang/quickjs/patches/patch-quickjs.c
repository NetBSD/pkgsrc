$NetBSD: patch-quickjs.c,v 1.5 2025/11/12 11:49:38 leot Exp $

Portability patch for NetBSD.

--- quickjs.c.orig	2025-09-13 08:48:28.000000000 +0000
+++ quickjs.c
@@ -69,7 +69,15 @@
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
@@ -1669,7 +1677,7 @@ static size_t js_def_malloc_usable_size(
     return malloc_size(ptr);
 #elif defined(_WIN32)
     return _msize((void *)ptr);
-#elif defined(EMSCRIPTEN)
+#elif defined(EMSCRIPTEN) || defined(__NetBSD__)
     return 0;
 #elif defined(__linux__) || defined(__GLIBC__)
     return malloc_usable_size((void *)ptr);
