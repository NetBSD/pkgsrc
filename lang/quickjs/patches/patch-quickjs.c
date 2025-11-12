$NetBSD: patch-quickjs.c,v 1.6 2025/11/12 11:58:20 leot Exp $

- Portability patch for NetBSD.
- Backport commit c6fe5a98fd3ef3b7064e6e0145dfebfe12449fea to fix
  CVE-2025-12745.

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
@@ -52988,7 +52996,7 @@ static JSValue js_array_buffer_slice(JSC
         goto fail;
     }
     /* must test again because of side effects */
-    if (abuf->detached) {
+    if (abuf->detached || abuf->byte_length < start + new_len) {
         JS_ThrowTypeErrorDetachedArrayBuffer(ctx);
         goto fail;
     }
