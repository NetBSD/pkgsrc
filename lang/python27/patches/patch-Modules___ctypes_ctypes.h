$NetBSD: patch-Modules___ctypes_ctypes.h,v 1.1 2021/06/23 18:30:24 schmonz Exp $

macOS arm64 support, via MacPorts.

--- Modules/_ctypes/ctypes.h.orig	2021-06-22 19:20:03.000000000 +0000
+++ Modules/_ctypes/ctypes.h
@@ -481,6 +481,13 @@ static void capsule_destructor_ ## name(
 
 #endif /* PY_VERSION_HEX >= 0x020700A4 */
 
+#if USING_MALLOC_CLOSURE_DOT_C
+void Py_ffi_closure_free(void *p);
+void *Py_ffi_closure_alloc(size_t size, void** codeloc);
+#else
+#define Py_ffi_closure_free ffi_closure_free
+#define Py_ffi_closure_alloc ffi_closure_alloc
+#endif
 
 /*
  Local Variables:
