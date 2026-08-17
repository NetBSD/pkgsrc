$NetBSD: patch-numpy___core_src_multiarray_arrayobject.c,v 1.1 2026/08/17 09:27:49 adam Exp $

Avoid static_assert in C.

--- numpy/_core/src/multiarray/arrayobject.c.orig	2026-08-14 12:32:59.056345672 +0000
+++ numpy/_core/src/multiarray/arrayobject.c
@@ -1296,22 +1296,8 @@ NPY_NO_EXPORT PyTypeObject PyArray_Type
  * We can choose that this is fine or increase the padding to 16/max_align_t when it happens.
  * (See comments in `ndarraytypes.h` for more details.)
  */
-static_assert(sizeof(PyObject) % 16 == 0,
-    "Expected sizeof(PyObject) to be multiple of 16 on 64bit builds.");
 #endif
 
-static_assert(NPY_ALIGNOF(PyArray_Descr_fields) <= 8,
-              "PyArray_Descr must not require more than 8-byte alignment");
-static_assert(NPY_ALIGNOF(_PyArray_LegacyDescr_fields) <= 8,
-              "_PyArray_LegacyDescr must not require more than 8-byte alignment");
-static_assert(NPY_ALIGNOF(PyArrayObject_fields) <= 8,
-              "PyArrayObject must not require more than 8-byte alignment");
-static_assert(NPY_ALIGNOF(PyArrayMultiIterObject_fields) <= 8,
-              "PyArrayMultiIterObject must not require more than 8-byte alignment");
-static_assert(NPY_ALIGNOF(PyArrayIterObject_fields) <= 8,
-              "PyArrayIterObject must not require more than 8-byte alignment");
-static_assert(NPY_ALIGNOF(PyArrayNeighborhoodIterObject_fields) <= 8,
-              "PyArrayNeighborhoodIterObject must not require more than 8-byte alignment");
 #undef _PyDataType_GET_ITEM_DATA
 /*NUMPY_API*/
 NPY_NO_EXPORT PyArray_Descr_fields *
