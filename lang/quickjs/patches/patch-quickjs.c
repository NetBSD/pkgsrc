$NetBSD: patch-quickjs.c,v 1.8 2026/06/28 17:59:25 osa Exp $

- Portability patch for NetBSD.

--- quickjs.c.orig	2026-06-04 08:26:08.000000000 -0400
+++ quickjs.c	2026-06-28 13:52:10.705459429 -0400
@@ -69,7 +69,15 @@
 /* define to include Atomics.* operations which depend on the OS
    threads */
 #if !defined(__EMSCRIPTEN__)
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
 
 #if !defined(__EMSCRIPTEN__)
@@ -2140,7 +2148,7 @@
     return malloc_size(ptr);
 #elif defined(_WIN32)
     return _msize((void *)ptr);
-#elif defined(__EMSCRIPTEN__)
+#elif defined(__EMSCRIPTEN__) || defined(__NetBSD__)
     return 0;
 #elif defined(__linux__) || defined(__GLIBC__)
     return malloc_usable_size((void *)ptr);
