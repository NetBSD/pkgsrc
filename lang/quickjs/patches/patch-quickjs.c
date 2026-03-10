$NetBSD: patch-quickjs.c,v 1.7 2026/03/10 17:24:10 osa Exp $

- Portability patch for NetBSD.

--- quickjs.c.orig	2026-03-05 15:33:25.381847153 +0000
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
@@ -1721,7 +1729,7 @@ static size_t js_def_malloc_usable_size(
     return malloc_size(ptr);
 #elif defined(_WIN32)
     return _msize((void *)ptr);
-#elif defined(EMSCRIPTEN)
+#elif defined(EMSCRIPTEN) || defined(__NetBSD__)
     return 0;
 #elif defined(__linux__) || defined(__GLIBC__)
     return malloc_usable_size((void *)ptr);
