$NetBSD: patch-scipy_spatial___ckdtree.pyx,v 1.1 2023/05/08 20:39:18 tnn Exp $

Fix missing isnan/isinf.

--- scipy/spatial/_ckdtree.pyx.orig	1970-01-01 00:00:00.000000000 +0000
+++ scipy/spatial/_ckdtree.pyx
@@ -15,7 +15,8 @@ from numpy.math cimport INFINITY
 from cpython.mem cimport PyMem_Malloc, PyMem_Free
 from libcpp.vector cimport vector
 from libcpp cimport bool
-from libc.math cimport isinf
+cdef extern from "<cmath>" namespace "std":
+    bool isinf(double)
 
 cimport cython
 import os
