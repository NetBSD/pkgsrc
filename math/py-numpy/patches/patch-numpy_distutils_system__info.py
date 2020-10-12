$NetBSD: patch-numpy_distutils_system__info.py,v 1.3 2020/10/12 21:51:58 bacon Exp $

Disable openblas detection.  In pkgsrc, use mk/blas.buildlink.mk.

--- numpy/distutils/system_info.py.orig	2020-04-19 08:51:58.000000000 +0000
+++ numpy/distutils/system_info.py
@@ -1644,14 +1644,6 @@ class lapack_opt_info(system_info):
         return False
 
     def _calc_info_openblas(self):
-        info = get_info('openblas_lapack')
-        if info:
-            self.set_info(**info)
-            return True
-        info = get_info('openblas_clapack')
-        if info:
-            self.set_info(**info)
-            return True
         return False
 
     def _calc_info_flame(self):
