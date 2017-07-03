$NetBSD: patch-c___cffi__backend.c,v 1.1 2017/07/03 18:17:45 joerg Exp $

--- c/_cffi_backend.c.orig	2017-03-21 10:41:29.000000000 +0000
+++ c/_cffi_backend.c
@@ -60,8 +60,6 @@
 # endif
 #endif
 
-#include "malloc_closure.h"
-
 #if PY_MAJOR_VERSION >= 3
 # define STR_OR_BYTES "bytes"
 # define PyText_Type PyUnicode_Type
@@ -256,6 +254,11 @@ typedef struct {
 } CDataObject_gcp;
 
 typedef struct {
+    CDataObject head;
+    ffi_closure *closure;
+} CDataObject_closure;
+
+typedef struct {
     ffi_cif cif;
     /* the following information is used when doing the call:
        - a buffer of size 'exchange_size' is malloced
@@ -1678,10 +1681,10 @@ static void cdataowninggc_dealloc(CDataO
         Py_DECREF(x);
     }
     else if (cd->c_type->ct_flags & CT_FUNCTIONPTR) {   /* a callback */
-        ffi_closure *closure = (ffi_closure *)cd->c_data;
-        PyObject *args = (PyObject *)(closure->user_data);
+        ffi_closure *closure = ((CDataObject_closure *)cd)->closure;
+        PyObject *args = (PyObject *)closure->user_data;
         Py_XDECREF(args);
-        cffi_closure_free(closure);
+        ffi_closure_free(closure);
     }
     else if (cd->c_type->ct_flags & CT_IS_UNSIZED_CHAR_A) {  /* from_buffer */
         Py_buffer *view = ((CDataObject_owngc_frombuf *)cd)->bufferview;
@@ -1698,8 +1701,8 @@ static int cdataowninggc_traverse(CDataO
         Py_VISIT(x);
     }
     else if (cd->c_type->ct_flags & CT_FUNCTIONPTR) {   /* a callback */
-        ffi_closure *closure = (ffi_closure *)cd->c_data;
-        PyObject *args = (PyObject *)(closure->user_data);
+        ffi_closure *closure = ((CDataObject_closure *)cd)->closure;
+        PyObject *args = (PyObject *)closure->user_data;
         Py_VISIT(args);
     }
     else if (cd->c_type->ct_flags & CT_IS_UNSIZED_CHAR_A) {  /* from_buffer */
@@ -1719,8 +1722,8 @@ static int cdataowninggc_clear(CDataObje
         Py_DECREF(x);
     }
     else if (cd->c_type->ct_flags & CT_FUNCTIONPTR) {   /* a callback */
-        ffi_closure *closure = (ffi_closure *)cd->c_data;
-        PyObject *args = (PyObject *)(closure->user_data);
+        ffi_closure *closure = ((CDataObject_closure *)cd)->closure;
+        PyObject *args = (PyObject *)closure->user_data;
         closure->user_data = NULL;
         Py_XDECREF(args);
     }
@@ -1925,7 +1928,8 @@ static PyObject *cdataowninggc_repr(CDat
         return _cdata_repr2(cd, "handle to", x);
     }
     else if (cd->c_type->ct_flags & CT_FUNCTIONPTR) {   /* a callback */
-        PyObject *args = (PyObject *)((ffi_closure *)cd->c_data)->user_data;
+        ffi_closure *closure = ((CDataObject_closure *)cd)->closure;
+        PyObject *args = (PyObject *)closure->user_data;
         if (args == NULL)
             return cdata_repr(cd);
         else
@@ -5488,11 +5492,12 @@ static PyObject *prepare_callback_info_t
 static PyObject *b_callback(PyObject *self, PyObject *args)
 {
     CTypeDescrObject *ct;
-    CDataObject *cd;
+    CDataObject_closure *cd;
     PyObject *ob, *error_ob = Py_None, *onerror_ob = Py_None;
     PyObject *infotuple;
     cif_description_t *cif_descr;
     ffi_closure *closure;
+    void *closure_exec;
 
     if (!PyArg_ParseTuple(args, "O!O|OO:callback", &CTypeDescr_Type, &ct, &ob,
                           &error_ob, &onerror_ob))
@@ -5502,15 +5507,20 @@ static PyObject *b_callback(PyObject *se
     if (infotuple == NULL)
         return NULL;
 
-    closure = cffi_closure_alloc();
+    closure = ffi_closure_alloc(sizeof(ffi_closure), &closure_exec);
+    if (closure == NULL) {
+        Py_DECREF(infotuple);
 
-    cd = PyObject_GC_New(CDataObject, &CDataOwningGC_Type);
+        return NULL;
+    }
+    cd = PyObject_GC_New(CDataObject_closure, &CDataOwningGC_Type);
     if (cd == NULL)
         goto error;
     Py_INCREF(ct);
-    cd->c_type = ct;
-    cd->c_data = (char *)closure;
-    cd->c_weakreflist = NULL;
+    cd->head.c_type = ct;
+    cd->head.c_data = (char *)closure_exec;
+    cd->head.c_weakreflist = NULL;
+    cd->closure = closure;
     PyObject_GC_Track(cd);
 
     cif_descr = (cif_description_t *)ct->ct_extra;
@@ -5520,8 +5530,8 @@ static PyObject *b_callback(PyObject *se
                      "return type or with '...'", ct->ct_name);
         goto error;
     }
-    if (ffi_prep_closure(closure, &cif_descr->cif,
-                         invoke_callback, infotuple) != FFI_OK) {
+    if (ffi_prep_closure_loc(closure, &cif_descr->cif,
+                         invoke_callback, infotuple, closure_exec) != FFI_OK) {
         PyErr_SetString(PyExc_SystemError,
                         "libffi failed to build this callback");
         goto error;
@@ -5545,7 +5555,7 @@ static PyObject *b_callback(PyObject *se
  error:
     closure->user_data = NULL;
     if (cd == NULL)
-        cffi_closure_free(closure);
+        ffi_closure_free(closure);
     else
         Py_DECREF(cd);
     Py_XDECREF(infotuple);
