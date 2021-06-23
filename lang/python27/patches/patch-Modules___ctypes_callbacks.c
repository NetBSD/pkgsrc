$NetBSD: patch-Modules___ctypes_callbacks.c,v 1.1 2021/06/23 18:30:24 schmonz Exp $

macOS arm64 support, via MacPorts.

--- Modules/_ctypes/callbacks.c.orig	2021-06-22 19:20:03.000000000 +0000
+++ Modules/_ctypes/callbacks.c
@@ -24,7 +24,7 @@ CThunkObject_dealloc(PyObject *_self)
     Py_XDECREF(self->callable);
     Py_XDECREF(self->restype);
     if (self->pcl_write)
-        ffi_closure_free(self->pcl_write);
+        Py_ffi_closure_free(self->pcl_write);
     PyObject_GC_Del(self);
 }
 
@@ -426,7 +426,7 @@ CThunkObject *_ctypes_alloc_callback(PyO
 
     assert(CThunk_CheckExact(p));
 
-    p->pcl_write = ffi_closure_alloc(sizeof(ffi_closure),
+    p->pcl_write = Py_ffi_closure_alloc(sizeof(ffi_closure),
 				     &p->pcl_exec);
     if (p->pcl_write == NULL) {
         PyErr_NoMemory();
@@ -473,12 +473,15 @@ CThunkObject *_ctypes_alloc_callback(PyO
                      "ffi_prep_cif failed with %d", result);
         goto error;
     }
-#if defined(X86_DARWIN) || defined(POWERPC_DARWIN)
-    result = ffi_prep_closure(p->pcl_write, &p->cif, closure_fcn, p);
-#else
+#if HAVE_FFI_PREP_CLOSURE_LOC
     result = ffi_prep_closure_loc(p->pcl_write, &p->cif, closure_fcn,
 				  p,
 				  p->pcl_exec);
+#elif defined(__APPLE__) && defined(__arm64__)
+    PyErr_Format(PyExc_NotImplementedError, "ffi_prep_closure_loc() is missing");
+    goto error;
+#else
+    result = ffi_prep_closure(p->pcl_write, &p->cif, closure_fcn, p);
 #endif
     if (result != FFI_OK) {
         PyErr_Format(PyExc_RuntimeError,
