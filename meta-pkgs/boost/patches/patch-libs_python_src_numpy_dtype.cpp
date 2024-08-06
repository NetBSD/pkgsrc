$NetBSD: patch-libs_python_src_numpy_dtype.cpp,v 1.1 2024/08/06 09:54:56 adam Exp $

Support numpy 2.0.0b1
https://github.com/boostorg/python/pull/432

--- libs/python/src/numpy/dtype.cpp.orig	2024-08-06 09:52:03.876685530 +0000
+++ libs/python/src/numpy/dtype.cpp
@@ -98,7 +98,13 @@ python::detail::new_reference dtype::con
   return python::detail::new_reference(reinterpret_cast<PyObject*>(obj));
 }
 
-int dtype::get_itemsize() const { return reinterpret_cast<PyArray_Descr*>(ptr())->elsize;}
+int dtype::get_itemsize() const {
+#if NPY_ABI_VERSION < 0x02000000
+  return reinterpret_cast<PyArray_Descr*>(ptr())->elsize;
+#else
+  return PyDataType_ELSIZE(reinterpret_cast<PyArray_Descr*>(ptr()));
+#endif
+}
 
 bool equivalent(dtype const & a, dtype const & b) {
     // On Windows x64, the behaviour described on 
