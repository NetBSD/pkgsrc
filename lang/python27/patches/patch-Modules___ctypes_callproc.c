$NetBSD: patch-Modules___ctypes_callproc.c,v 1.2 2021/10/10 03:00:59 gutteridge Exp $

macOS arm64 support, via MacPorts.

Fix CVE-2021-3177: Replace snprintf with Python unicode formatting in ctypes param reprs
Via Fedora:
https://src.fedoraproject.org/rpms/python2.7/blob/rawhide/f/00357-CVE-2021-3177.patch

--- Modules/_ctypes/callproc.c.orig	2020-04-19 21:13:39.000000000 +0000
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
@@ -460,50 +464,62 @@ PyCArg_dealloc(PyCArgObject *self)
 static PyObject *
 PyCArg_repr(PyCArgObject *self)
 {
-    char buffer[256];
     switch(self->tag) {
     case 'b':
     case 'B':
-        sprintf(buffer, "<cparam '%c' (%d)>",
+        return PyString_FromFormat("<cparam '%c' (%d)>",
             self->tag, self->value.b);
-        break;
     case 'h':
     case 'H':
-        sprintf(buffer, "<cparam '%c' (%d)>",
+        return PyString_FromFormat("<cparam '%c' (%d)>",
             self->tag, self->value.h);
-        break;
     case 'i':
     case 'I':
-        sprintf(buffer, "<cparam '%c' (%d)>",
+        return PyString_FromFormat("<cparam '%c' (%d)>",
             self->tag, self->value.i);
-        break;
     case 'l':
     case 'L':
-        sprintf(buffer, "<cparam '%c' (%ld)>",
+        return PyString_FromFormat("<cparam '%c' (%ld)>",
             self->tag, self->value.l);
-        break;
 
 #ifdef HAVE_LONG_LONG
     case 'q':
     case 'Q':
-        sprintf(buffer,
-            "<cparam '%c' (%" PY_FORMAT_LONG_LONG "d)>",
+        return PyString_FromFormat("<cparam '%c' (%lld)>",
             self->tag, self->value.q);
-        break;
 #endif
     case 'd':
-        sprintf(buffer, "<cparam '%c' (%f)>",
-            self->tag, self->value.d);
-        break;
-    case 'f':
-        sprintf(buffer, "<cparam '%c' (%f)>",
-            self->tag, self->value.f);
-        break;
-
+    case 'f': {
+        PyObject *s = PyString_FromFormat("<cparam '%c' (", self->tag);
+        if (s == NULL) {
+            return NULL;
+        }
+        PyObject *f = PyFloat_FromDouble((self->tag == 'f') ? self->value.f : self->value.d);
+        if (f == NULL) {
+            Py_DECREF(s);
+            return NULL;
+        }
+        PyObject *r = PyObject_Repr(f);
+        Py_DECREF(f);
+        if (r == NULL) {
+            Py_DECREF(s);
+            return NULL;
+        }
+        PyString_ConcatAndDel(&s, r);
+        if (s == NULL) {
+            return NULL;
+        }
+        r = PyString_FromString(")>");
+        if (r == NULL) {
+            Py_DECREF(s);
+            return NULL;
+        }
+        PyString_ConcatAndDel(&s, r);
+        return s;
+    }
     case 'c':
-        sprintf(buffer, "<cparam '%c' (%c)>",
+        return PyString_FromFormat("<cparam '%c' ('%c')>",
             self->tag, self->value.c);
-        break;
 
 /* Hm, are these 'z' and 'Z' codes useful at all?
    Shouldn't they be replaced by the functionality of c_string
@@ -512,16 +528,13 @@ PyCArg_repr(PyCArgObject *self)
     case 'z':
     case 'Z':
     case 'P':
-        sprintf(buffer, "<cparam '%c' (%p)>",
+        return PyUnicode_FromFormat("<cparam '%c' (%p)>",
             self->tag, self->value.p);
-        break;
 
     default:
-        sprintf(buffer, "<cparam '%c' at %p>",
-            self->tag, self);
-        break;
+        return PyString_FromFormat("<cparam '%c' at %p>",
+            (unsigned char)self->tag, (void *)self);
     }
-    return PyString_FromString(buffer);
 }
 
 static PyMemberDef PyCArgType_members[] = {
@@ -773,7 +786,8 @@ static int _call_function_pointer(int fl
                                   ffi_type **atypes,
                                   ffi_type *restype,
                                   void *resmem,
-                                  int argcount)
+                                  int argcount,
+                                  int argtypecount)
 {
 #ifdef WITH_THREAD
     PyThreadState *_save = NULL; /* For Py_BLOCK_THREADS and Py_UNBLOCK_THREADS */
@@ -801,6 +815,37 @@ static int _call_function_pointer(int fl
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
@@ -810,6 +855,7 @@ static int _call_function_pointer(int fl
                         "ffi_prep_cif failed");
         return -1;
     }
+    }
 
     if (flags & (FUNCFLAG_USE_ERRNO | FUNCFLAG_USE_LASTERROR)) {
         error_object = _ctypes_get_errobj(&space);
@@ -1183,6 +1229,9 @@ PyObject *_ctypes_callproc(PPROC pProc,
                                      rtype, resbuf,
                                      Py_SAFE_DOWNCAST(argcount,
                                                       Py_ssize_t,
+                                                      int),
+                                     Py_SAFE_DOWNCAST(argtype_count,
+                                                      Py_ssize_t,
                                                       int)))
         goto cleanup;
 
@@ -1416,6 +1465,25 @@ copy_com_pointer(PyObject *self, PyObjec
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
@@ -1940,6 +2008,9 @@ PyMethodDef _ctypes_module_methods[] = {
      "dlopen(name, flag={RTLD_GLOBAL|RTLD_LOCAL}) open a shared library"},
     {"dlclose", py_dl_close, METH_VARARGS, "dlclose a library"},
     {"dlsym", py_dl_sym, METH_VARARGS, "find symbol in shared library"},
+#if __APPLE__ && HAVE_DYLD_SHARED_CACHE_CONTAINS_PATH
+    {"_dyld_shared_cache_contains_path", py_dyld_shared_cache_contains_path, METH_VARARGS, "check if path is in the shared cache"},
+#endif
 #endif
     {"alignment", align_func, METH_O, alignment_doc},
     {"sizeof", sizeof_func, METH_O, sizeof_doc},
