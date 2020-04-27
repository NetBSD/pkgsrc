$NetBSD: patch-numpy_distutils_system__info.py,v 1.1 2020/04/27 16:52:56 adam Exp $

Disable openblas detection.  In pkgsrc, py-numpy should use math/blas.

--- numpy/distutils/system_info.py.orig	2018-04-02 21:18:11.535155000 +0000
+++ numpy/distutils/system_info.py
@@ -1531,12 +1531,12 @@ class lapack_opt_info(system_info):
             self.set_info(**lapack_mkl_info)
             return
 
-        openblas_info = get_info('openblas_lapack')
+        openblas_info = None
         if openblas_info:
             self.set_info(**openblas_info)
             return
 
-        openblas_info = get_info('openblas_clapack')
+        openblas_info = None
         if openblas_info:
             self.set_info(**openblas_info)
             return
@@ -1642,7 +1642,7 @@ class blas_opt_info(system_info):
             self.set_info(**blis_info)
             return
 
-        openblas_info = get_info('openblas')
+        openblas_info = None
         if openblas_info:
             self.set_info(**openblas_info)
             return
