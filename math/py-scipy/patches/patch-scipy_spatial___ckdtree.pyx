$NetBSD: patch-scipy_spatial___ckdtree.pyx,v 1.4 2023/07/17 19:39:56 tnn Exp $

Fix missing isnan/isinf.
Build breaks on at least NetBSD-10.99.4-aarch64 without this:

scipy/spatial/_ckdtree.cxx: In function 'PyObject* __pyx_pf_5scipy_7spatial_8_ckdtree_7cKDTree_16count_neighbors(__pyx_obj_5scipy_7spatial_8_ckdtree_cKDTree*, __pyx_obj_5scipy_7spatial_8_ckdtree_cKDTree*, PyObject*, __pyx_t_5numpy_float64_t, PyObject*, int)':
scipy/spatial/_ckdtree.cxx:13392:19: error: 'isinf' was not declared in this scope; did you mean 'std::isinf'?

--- scipy/spatial/_ckdtree.pyx.orig	1970-01-01 00:00:00.000000000 +0000
+++ scipy/spatial/_ckdtree.pyx
@@ -16,7 +16,9 @@ cimport numpy as np
 from cpython.mem cimport PyMem_Malloc, PyMem_Free
 from libcpp.vector cimport vector
 from libcpp cimport bool
-from libc.math cimport isinf, INFINITY
+from libc.math cimport INFINITY
+cdef extern from "<cmath>" namespace "std":
+    bool isinf(double)
 
 cimport cython
 import os
