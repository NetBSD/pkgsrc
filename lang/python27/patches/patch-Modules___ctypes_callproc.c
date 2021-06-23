$NetBSD: patch-Modules___ctypes_callproc.c,v 1.1 2021/06/23 18:30:24 schmonz Exp $

macOS arm64 support, via MacPorts.

--- Modules/_ctypes/callproc.c.orig	2021-06-22 19:20:28.000000000 +0000
+++ Modules/_ctypes/callproc.c
@@ -74,6 +74,10 @@
 #include <malloc.h>
 #endif
 
+#if __APPLE__ && HAVE_DYLD_SHARED_CACHE_CONTAINS_PATH
+#include <mach-o/dyld.h>
+#endif
+
 #include <ffi.h>
 #include "ctypes.h"
 #ifdef HAVE_ALLOCA_H
@@ -773,7 +777,8 @@ static int _call_function_pointer(int fl
                                   ffi_type **atypes,
                                   ffi_type *restype,
                                   void *resmem,
-                                  int argcount)
+                                  int argcount,
+                                  int argtypecount)
 {
 #ifdef WITH_THREAD
     PyThreadState *_save = NULL; /* For Py_BLOCK_THREADS and Py_UNBLOCK_THREADS */
@@ -801,6 +806,37 @@ static int _call_function_pointer(int fl
     if ((flags & FUNCFLAG_CDECL) == 0)
         cc = FFI_STDCALL;
 #endif
+
+    /* Even on Apple-arm64 the calling convention for variadic functions conincides
+    * with the standard calling convention in the case that the function called
+    * only with its fixed arguments.   Thus, we do not need a special flag to be
+    * set on variadic functions.   We treat a function as variadic if it is called
+    * with a nonzero number of variadic arguments */
+    int is_variadic = (argtypecount != 0 && argcount > argtypecount);
+    (void) is_variadic;
+
+#if defined(__APPLE__) && defined(__arm64__) && !defined(HAVE_FFI_PREP_CIF_VAR)
+    if (is_variadic) {
+        PyErr_SetString(PyExc_NotImplementedError, "ffi_prep_cif_var() is missing");
+        return -1;
+    }
+#endif
+
+#if HAVE_FFI_PREP_CIF_VAR
+    if (is_variadic) {
+        if (FFI_OK != ffi_prep_cif_var(&cif,
+                                        cc,
+                                        argtypecount,
+                                        argcount,
+                                        restype,
+                                        atypes)) {
+            PyErr_SetString(PyExc_RuntimeError,
+                            "ffi_prep_cif_var failed");
+            return -1;
+        }
+    } else
+ #endif
+    {
     if (FFI_OK != ffi_prep_cif(&cif,
                                cc,
                                argcount,
@@ -810,6 +846,7 @@ static int _call_function_pointer(int fl
                         "ffi_prep_cif failed");
         return -1;
     }
+    }
 
     if (flags & (FUNCFLAG_USE_ERRNO | FUNCFLAG_USE_LASTERROR)) {
         error_object = _ctypes_get_errobj(&space);
@@ -1183,6 +1220,9 @@ PyObject *_ctypes_callproc(PPROC pProc,
                                      rtype, resbuf,
                                      Py_SAFE_DOWNCAST(argcount,
                                                       Py_ssize_t,
+                                                      int),
+                                     Py_SAFE_DOWNCAST(argtype_count,
+                                                      Py_ssize_t,
                                                       int)))
         goto cleanup;
 
@@ -1416,6 +1456,25 @@ copy_com_pointer(PyObject *self, PyObjec
 }
 #else
 
+#if __APPLE__ && HAVE_DYLD_SHARED_CACHE_CONTAINS_PATH
+static PyObject *py_dyld_shared_cache_contains_path(PyObject *self, PyObject *args)
+{
+    if (__builtin_available(macos 11, ios 14, watchos 7, tvos 14, *)) {
+        char *name_str;
+        if (!PyArg_ParseTuple(args, "z", &name_str))
+            return NULL;
+
+        if(_dyld_shared_cache_contains_path(name_str))
+            Py_RETURN_TRUE;
+        else
+            Py_RETURN_FALSE;
+    } else {
+        PyErr_SetString(PyExc_NotImplementedError, "_dyld_shared_cache_contains_path symbol is missing");
+        return NULL;
+    }
+}
+#endif
+
 static PyObject *py_dl_open(PyObject *self, PyObject *args)
 {
     char *name;
@@ -1940,6 +1999,9 @@ PyMethodDef _ctypes_module_methods[] = {
      "dlopen(name, flag={RTLD_GLOBAL|RTLD_LOCAL}) open a shared library"},
     {"dlclose", py_dl_close, METH_VARARGS, "dlclose a library"},
     {"dlsym", py_dl_sym, METH_VARARGS, "find symbol in shared library"},
+#if __APPLE__ && HAVE_DYLD_SHARED_CACHE_CONTAINS_PATH
+    {"_dyld_shared_cache_contains_path", py_dyld_shared_cache_contains_path, METH_VARARGS, "check if path is in the shared cache"},
+#endif
 #endif
     {"alignment", align_func, METH_O, alignment_doc},
     {"sizeof", sizeof_func, METH_O, sizeof_doc},
