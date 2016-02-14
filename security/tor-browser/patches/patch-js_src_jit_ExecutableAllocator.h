$NetBSD: patch-js_src_jit_ExecutableAllocator.h,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- js/src/jit/ExecutableAllocator.h.orig	2015-05-04 00:43:27.000000000 +0000
+++ js/src/jit/ExecutableAllocator.h
@@ -419,6 +419,11 @@ class ExecutableAllocator {
     {
         __clear_cache(code, reinterpret_cast<char*>(code) + size);
     }
+#elif defined(JS_CODEGEN_ARM) && (defined(__FreeBSD__) || defined(__NetBSD__))
+    static void cacheFlush(void* code, size_t size)
+    {
+        __clear_cache(code, reinterpret_cast<char*>(code) + size);
+    }
 #elif defined(JS_CODEGEN_ARM) && (defined(__linux__) || defined(ANDROID)) && defined(__GNUC__)
     static void cacheFlush(void* code, size_t size)
     {
