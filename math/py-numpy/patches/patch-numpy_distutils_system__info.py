$NetBSD: patch-numpy_distutils_system__info.py,v 1.6 2021/04/07 11:57:30 thor Exp $

Introduce new option 'generic' for BLAS and LAPACK
TODO: The same for 64 bit offset versions, but we'd need repspective BLAS builds
first in pkgsrc to test.

--- numpy/distutils/system_info.py.orig	2021-01-04 14:16:38.000000000 +0000
+++ numpy/distutils/system_info.py
@@ -114,6 +114,13 @@ Currently, the following classes are ava
     x11_info:x11
     xft_info:xft
 
+Note that blas_opt_info and lapack_opt_info honor the NPY_BLAS_ORDER and NPY_LAPACK_ORDER
+environment variables to select a specific implementation. One possible implementation
+is 'generic', which relies on the environment providing BLAS_LIBS and LAPACK_LIBS to
+link to the customary plain f77 interface, supporting any standard-conforming BLAS
+and LAPACK implementation (which might be different between build-time and run-time,
+even).
+
 Example:
 ----------
 [DEFAULT]
@@ -1651,7 +1658,7 @@ def get_atlas_version(**config):
 class lapack_opt_info(system_info):
     notfounderror = LapackNotFoundError
     # List of all known BLAS libraries, in the default order
-    lapack_order = ['mkl', 'openblas', 'flame', 'atlas', 'accelerate', 'lapack']
+    lapack_order = ['generic', 'mkl', 'openblas', 'flame', 'atlas', 'accelerate', 'lapack']
     order_env_var_name = 'NPY_LAPACK_ORDER'
 
     def _calc_info_mkl(self):
@@ -1744,6 +1751,18 @@ class lapack_opt_info(system_info):
             return True
         return False
 
+    def _calc_info_generic(self):
+        if 'LAPACK_LIBS' in os.environ:
+            info = {}
+            info['language'] = 'f77'
+            info['libraries'] = []
+            info['include_dirs'] = []
+            info['define_macros'] = []
+            info['extra_link_args'] = os.environ['LAPACK_LIBS'].split()
+            self.set_info(**info)
+            return True
+        return False
+
     def _calc_info(self, name):
         return getattr(self, '_calc_info_{}'.format(name))()
 
@@ -1823,7 +1842,7 @@ class lapack64__opt_info(lapack_ilp64_op
 class blas_opt_info(system_info):
     notfounderror = BlasNotFoundError
     # List of all known BLAS libraries, in the default order
-    blas_order = ['mkl', 'blis', 'openblas', 'atlas', 'accelerate', 'blas']
+    blas_order = ['generic', 'mkl', 'blis', 'openblas', 'atlas', 'accelerate', 'blas']
     order_env_var_name = 'NPY_BLAS_ORDER'
 
     def _calc_info_mkl(self):
@@ -1889,6 +1908,18 @@ class blas_opt_info(system_info):
         self.set_info(**info)
         return True
 
+    def _calc_info_generic(self):
+        if 'BLAS_LIBS' in os.environ:
+            info = {}
+            info['language'] = 'f77'
+            info['libraries'] = []
+            info['include_dirs'] = []
+            info['define_macros'] = []
+            info['extra_link_args'] = os.environ['BLAS_LIBS'].split()
+            self.set_info(**info)
+            return True
+        return False
+
     def _calc_info(self, name):
         return getattr(self, '_calc_info_{}'.format(name))()
 
