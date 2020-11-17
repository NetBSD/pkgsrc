$NetBSD: patch-Modules___ctypes_callproc.c,v 1.1 2020/11/17 19:33:26 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Mostly backported from:
https://github.com/python/cpython/pull/22855

--- Modules/_ctypes/callproc.c.orig	2020-08-15 05:20:16.000000000 +0000
+++ Modules/_ctypes/callproc.c
@@ -57,6 +57,8 @@
 #include "Python.h"
 #include "structmember.h"
 
+#include <stdbool.h>
+
 #ifdef MS_WIN32
 #include <windows.h>
 #include <tchar.h>
@@ -64,6 +66,10 @@
 #include "ctypes_dlfcn.h"
 #endif
 
+#ifdef __APPLE__
+#include <mach-o/dyld.h>
+#endif
+
 #ifdef MS_WIN32
 #include <malloc.h>
 #endif
@@ -767,7 +773,8 @@ static int _call_function_pointer(int fl
                                   ffi_type **atypes,
                                   ffi_type *restype,
                                   void *resmem,
-                                  int argcount)
+                                  int argcount,
+                                  int argtypecount)
 {
     PyThreadState *_save = NULL; /* For Py_BLOCK_THREADS and Py_UNBLOCK_THREADS */
     PyObject *error_object = NULL;
@@ -793,14 +800,70 @@ static int _call_function_pointer(int fl
     if ((flags & FUNCFLAG_CDECL) == 0)
         cc = FFI_STDCALL;
 #endif
-    if (FFI_OK != ffi_prep_cif(&cif,
-                               cc,
-                               argcount,
-                               restype,
-                               atypes)) {
-        PyErr_SetString(PyExc_RuntimeError,
-                        "ffi_prep_cif failed");
-        return -1;
+
+#   if USING_APPLE_OS_LIBFFI
+#      define HAVE_FFI_PREP_CIF_VAR_RUNTIME __builtin_available(macos 10.15, ios 13, watchos 6, tvos 13, *)
+#   elif HAVE_FFI_PREP_CIF_VAR
+#      define HAVE_FFI_PREP_CIF_VAR_RUNTIME true
+#   else
+#      define HAVE_FFI_PREP_CIF_VAR_RUNTIME false
+#   endif
+
+    /* Even on Apple-arm64 the calling convention for variadic functions conincides
+     * with the standard calling convention in the case that the function called
+     * only with its fixed arguments.   Thus, we do not need a special flag to be
+     * set on variadic functions.   We treat a function as variadic if it is called
+     * with a nonzero number of variadic arguments */
+    bool is_variadic = (argtypecount != 0 && argcount > argtypecount);
+    (void) is_variadic;
+
+#if defined(__APPLE__) && defined(__arm64__)
+    if (is_variadic) {
+        if (HAVE_FFI_PREP_CIF_VAR_RUNTIME) {
+        } else {
+            PyErr_SetString(PyExc_NotImplementedError, "ffi_prep_cif_var() is missing");
+            return -1;
+        }
+    }
+#endif
+
+#if HAVE_FFI_PREP_CIF_VAR
+    if (is_variadic) {
+        if (HAVE_FFI_PREP_CIF_VAR_RUNTIME) {
+            if (FFI_OK != ffi_prep_cif_var(&cif,
+                                        cc,
+                                        argtypecount,
+                                        argcount,
+                                        restype,
+                                        atypes)) {
+                PyErr_SetString(PyExc_RuntimeError,
+                                "ffi_prep_cif_var failed");
+                return -1;
+            }
+        } else {
+            if (FFI_OK != ffi_prep_cif(&cif,
+                                       cc,
+                                       argcount,
+                                       restype,
+                                       atypes)) {
+                PyErr_SetString(PyExc_RuntimeError,
+                                "ffi_prep_cif failed");
+                return -1;
+            }
+        }
+    } else
+#endif
+
+    {
+        if (FFI_OK != ffi_prep_cif(&cif,
+                                   cc,
+                                   argcount,
+                                   restype,
+                                   atypes)) {
+            PyErr_SetString(PyExc_RuntimeError,
+                            "ffi_prep_cif failed");
+            return -1;
+        }
     }
 
     if (flags & (FUNCFLAG_USE_ERRNO | FUNCFLAG_USE_LASTERROR)) {
@@ -1200,9 +1263,8 @@ PyObject *_ctypes_callproc(PPROC pProc,
 
     if (-1 == _call_function_pointer(flags, pProc, avalues, atypes,
                                      rtype, resbuf,
-                                     Py_SAFE_DOWNCAST(argcount,
-                                                      Py_ssize_t,
-                                                      int)))
+                                     Py_SAFE_DOWNCAST(argcount, Py_ssize_t, int),
+                                     Py_SAFE_DOWNCAST(argtype_count, Py_ssize_t, int)))
         goto cleanup;
 
 #ifdef WORDS_BIGENDIAN
@@ -1354,6 +1416,42 @@ copy_com_pointer(PyObject *self, PyObjec
 }
 #else
 
+#ifdef HAVE_DYLD_SHARED_CACHE_CONTAINS_PATH
+static PyObject *py_dyld_shared_cache_contains_path(PyObject *self, PyObject *args)
+{
+     PyObject *name, *name2;
+     char *name_str;
+
+     if (__builtin_available(macOS 11.0, iOS 14.0, tvOS 14.0, watchOS 7.0, *)) {
+         int r;
+
+         if (!PyArg_ParseTuple(args, "O", &name))
+             return NULL;
+
+         if (name == Py_None)
+             Py_RETURN_FALSE;
+
+         if (PyUnicode_FSConverter(name, &name2) == 0)
+             return NULL;
+         name_str = PyBytes_AS_STRING(name2);
+
+         r = _dyld_shared_cache_contains_path(name_str);
+         Py_DECREF(name2);
+
+         if (r) {
+             Py_RETURN_TRUE;
+         } else {
+             Py_RETURN_FALSE;
+         }
+
+     } else {
+         PyErr_SetString(PyExc_NotImplementedError, "_dyld_shared_cache_contains_path symbol is missing");
+         return NULL;
+     }
+
+ }
+#endif
+
 static PyObject *py_dl_open(PyObject *self, PyObject *args)
 {
     PyObject *name, *name2;
@@ -1840,6 +1940,9 @@ PyMethodDef _ctypes_module_methods[] = {
     {"dlclose", py_dl_close, METH_VARARGS, "dlclose a library"},
     {"dlsym", py_dl_sym, METH_VARARGS, "find symbol in shared library"},
 #endif
+#ifdef HAVE_DYLD_SHARED_CACHE_CONTAINS_PATH
+     {"_dyld_shared_cache_contains_path", py_dyld_shared_cache_contains_path, METH_VARARGS, "check if path is in the shared cache"},
+#endif
     {"alignment", align_func, METH_O, alignment_doc},
     {"sizeof", sizeof_func, METH_O, sizeof_doc},
     {"byref", byref, METH_VARARGS, byref_doc},
