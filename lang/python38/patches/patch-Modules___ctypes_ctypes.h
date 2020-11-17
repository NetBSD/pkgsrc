$NetBSD: patch-Modules___ctypes_ctypes.h,v 1.1 2020/11/17 19:33:15 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Mostly backported from:
https://github.com/python/cpython/pull/22855

--- Modules/_ctypes/ctypes.h.orig	2020-09-23 12:36:32.000000000 +0000
+++ Modules/_ctypes/ctypes.h
@@ -366,6 +366,14 @@ PyObject *_ctypes_get_errobj(int **pspac
 extern PyObject *ComError;
 #endif
 
+#if USING_MALLOC_CLOSURE_DOT_C
+void Py_ffi_closure_free(void *p);
+void *Py_ffi_closure_alloc(size_t size, void** codeloc);
+#else
+#define Py_ffi_closure_free ffi_closure_free
+#define Py_ffi_closure_alloc ffi_closure_alloc
+#endif
+
 /*
  Local Variables:
  compile-command: "python setup.py -q build install --home ~"
