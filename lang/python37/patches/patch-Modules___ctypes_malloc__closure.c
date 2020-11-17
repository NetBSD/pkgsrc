$NetBSD: patch-Modules___ctypes_malloc__closure.c,v 1.1 2020/11/17 19:33:26 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Mostly backported from:
https://github.com/python/cpython/pull/22855

--- Modules/_ctypes/malloc_closure.c.orig	2020-08-15 05:20:16.000000000 +0000
+++ Modules/_ctypes/malloc_closure.c
@@ -89,16 +89,27 @@ static void more_core(void)
 /******************************************************************/
 
 /* put the item back into the free list */
-void ffi_closure_free(void *p)
+void Py_ffi_closure_free(void *p)
 {
+#if USING_APPLE_OS_LIBFFI && HAVE_FFI_CLOSURE_ALLOC
+    if (__builtin_available(macos 10.15, ios 13, watchos 6, tvos 13, *)) {
+        ffi_closure_free(p);
+        return;
+    }
+#endif
     ITEM *item = (ITEM *)p;
     item->next = free_list;
     free_list = item;
 }
 
 /* return one item from the free list, allocating more if needed */
-void *ffi_closure_alloc(size_t ignored, void** codeloc)
+void *Py_ffi_closure_alloc(size_t size, void** codeloc)
 {
+#if USING_APPLE_OS_LIBFFI && HAVE_FFI_CLOSURE_ALLOC
+    if (__builtin_available(macos 10.15, ios 13, watchos 6, tvos 13, *)) {
+        return ffi_closure_alloc(size, codeloc);
+    }
+#endif
     ITEM *item;
     if (!free_list)
         more_core();
