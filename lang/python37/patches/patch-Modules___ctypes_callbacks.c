$NetBSD: patch-Modules___ctypes_callbacks.c,v 1.3 2020/11/19 16:29:42 bsiegert Exp $

Support for macOS 11 and Apple Silicon (ARM). Mostly backported from:
https://github.com/python/cpython/pull/22855

--- Modules/_ctypes/callbacks.c.orig	2020-08-15 05:20:16.000000000 +0000
+++ Modules/_ctypes/callbacks.c
@@ -1,6 +1,8 @@
 #include "Python.h"
 #include "frameobject.h"
 
+#include <stdbool.h>
+
 #include <ffi.h>
 #ifdef MS_WIN32
 #include <windows.h>
@@ -18,7 +20,7 @@ CThunkObject_dealloc(PyObject *myself)
     Py_XDECREF(self->callable);
     Py_XDECREF(self->restype);
     if (self->pcl_write)
-        ffi_closure_free(self->pcl_write);
+        Py_ffi_closure_free(self->pcl_write);
     PyObject_GC_Del(self);
 }
 
@@ -341,8 +343,7 @@ CThunkObject *_ctypes_alloc_callback(PyO
 
     assert(CThunk_CheckExact((PyObject *)p));
 
-    p->pcl_write = ffi_closure_alloc(sizeof(ffi_closure),
-                                                                         &p->pcl_exec);
+    p->pcl_write = Py_ffi_closure_alloc(sizeof(ffi_closure), &p->pcl_exec);
     if (p->pcl_write == NULL) {
         PyErr_NoMemory();
         goto error;
@@ -388,13 +389,35 @@ CThunkObject *_ctypes_alloc_callback(PyO
                      "ffi_prep_cif failed with %d", result);
         goto error;
     }
-#if defined(X86_DARWIN) || defined(POWERPC_DARWIN)
-    result = ffi_prep_closure(p->pcl_write, &p->cif, closure_fcn, p);
+#if HAVE_FFI_PREP_CLOSURE_LOC
+#   if USING_APPLE_OS_LIBFFI
+#      define HAVE_FFI_PREP_CLOSURE_LOC_RUNTIME __builtin_available(macos 10.15, ios 13, watchos 6, tvos 13, *)
+#   else
+#      define HAVE_FFI_PREP_CLOSURE_LOC_RUNTIME 1
+#   endif
+    if (HAVE_FFI_PREP_CLOSURE_LOC_RUNTIME) {
+        result = ffi_prep_closure_loc(p->pcl_write, &p->cif, closure_fcn,
+                                    p,
+                                    p->pcl_exec);
+    } else
+#endif
+    {
+#if USING_APPLE_OS_LIBFFI && defined(__arm64__)
+        PyErr_Format(PyExc_NotImplementedError, "ffi_prep_closure_loc() is missing");
+        goto error;
 #else
-    result = ffi_prep_closure_loc(p->pcl_write, &p->cif, closure_fcn,
-                                  p,
-                                  p->pcl_exec);
+#ifdef MACOSX
+        #pragma clang diagnostic push
+        #pragma clang diagnostic ignored "-Wdeprecated-declarations"
 #endif
+        result = ffi_prep_closure(p->pcl_write, &p->cif, closure_fcn, p);
+
+#ifdef MACOSX
+        #pragma clang diagnostic pop
+#endif
+
+#endif
+    }
     if (result != FFI_OK) {
         PyErr_Format(PyExc_RuntimeError,
                      "ffi_prep_closure failed with %d", result);
