$NetBSD: patch-scipy_spatial___ckdtree.pyx,v 1.5 2026/06/30 09:57:45 adam Exp $

Fix missing isnan/isinf.
Build breaks on at least NetBSD-10.99.4-aarch64 without this:

scipy/spatial/_ckdtree.cxx: In function 'PyObject* __pyx_pf_5scipy_7spatial_8_ckdtree_7cKDTree_16count_neighbors(__pyx_obj_5scipy_7spatial_8_ckdtree_cKDTree*, __pyx_obj_5scipy_7spatial_8_ckdtree_cKDTree*, PyObject*, __pyx_t_5numpy_float64_t, PyObject*, int)':
scipy/spatial/_ckdtree.cxx:13392:19: error: 'isinf' was not declared in this scope; did you mean 'std::isinf'?

--- scipy/spatial/_ckdtree.pyx.orig	2026-06-19 03:00:59.000000000 +0000
+++ scipy/spatial/_ckdtree.pyx
@@ -17,7 +17,9 @@ from cpython.mem cimport PyMem_Malloc, P
 from libcpp.mutex cimport py_safe_call_once, py_safe_once_flag
 from libcpp.vector cimport vector
 from libcpp cimport bool
-from libc.math cimport isinf, INFINITY
+from libc.math cimport INFINITY
+cdef extern from "<cmath>" namespace "std":
+    bool isinf(double)
 
 cimport cython
 import os
