$NetBSD: patch-numpy___core_src_umath_ufunc__object.c,v 1.2 2026/08/17 09:58:06 wiz Exp $

Avoid static_assert in C.
https://github.com/numpy/numpy/issues/32308

--- numpy/_core/src/umath/ufunc_object.c.orig	2026-08-14 12:42:43.705330610 +0000
+++ numpy/_core/src/umath/ufunc_object.c
@@ -5489,8 +5489,6 @@ PyUFunc_RegisterLoopForType(PyUFuncObjec
 #undef _SETCPTR
 
 #undef _PyUFuncObject_GET_ITEM_DATA
-static_assert(NPY_ALIGNOF(PyUFuncObject_fields) <= 8,
-              "PyUFuncObject must not require more than 8-byte alignment");
 /*UFUNC_API*/
 NPY_NO_EXPORT PyUFuncObject_fields *
 _PyUFuncObject_GET_ITEM_DATA(const PyUFuncObject *obj)
