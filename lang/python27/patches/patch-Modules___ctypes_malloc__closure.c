$NetBSD: patch-Modules___ctypes_malloc__closure.c,v 1.1 2021/06/23 18:30:24 schmonz Exp $

macOS arm64 support, via MacPorts.

--- Modules/_ctypes/malloc_closure.c.orig	2021-06-22 19:20:03.000000000 +0000
+++ Modules/_ctypes/malloc_closure.c
@@ -89,16 +89,24 @@ static void more_core(void)
 /******************************************************************/
 
 /* put the item back into the free list */
-void ffi_closure_free(void *p)
+void Py_ffi_closure_free(void *p)
 {
+#if HAVE_FFI_CLOSURE_ALLOC
+    ffi_closure_free(p);
+    return;
+#else
     ITEM *item = (ITEM *)p;
     item->next = free_list;
     free_list = item;
+#endif
 }
 
 /* return one item from the free list, allocating more if needed */
-void *ffi_closure_alloc(size_t ignored, void** codeloc)
+void *Py_ffi_closure_alloc(size_t size, void** codeloc)
 {
+#if HAVE_FFI_CLOSURE_ALLOC
+    return ffi_closure_alloc(size, codeloc);
+#else
     ITEM *item;
     if (!free_list)
         more_core();
@@ -108,4 +116,5 @@ void *ffi_closure_alloc(size_t ignored, 
     free_list = item->next;
     *codeloc = (void *)item;
     return (void *)item;
+#endif
 }
