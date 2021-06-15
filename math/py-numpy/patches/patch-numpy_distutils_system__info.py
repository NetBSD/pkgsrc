$NetBSD: patch-numpy_distutils_system__info.py,v 1.9 2021/06/15 01:43:44 thor Exp $

Our BLAS choice in build system (merged upstream for next release).

--- numpy/distutils/system_info.py.orig	2021-03-27 09:52:12.000000000 +0000
+++ numpy/distutils/system_info.py
@@ -114,6 +114,19 @@ Currently, the following classes are ava
     x11_info:x11
     xft_info:xft
 
+Note that blas_opt_info and lapack_opt_info honor the NPY_BLAS_ORDER
+and NPY_LAPACK_ORDER environment variables to determine the order in which
+specific BLAS and LAPACK libraries are searched for.
+
+This search (or autodetection) can be bypassed by defining the environment
+variables NPY_BLAS_LIBS and NPY_LAPACK_LIBS, which should then contain the
+exact linker flags to use (language will be set to F77). Building against
+Netlib BLAS/LAPACK or stub files, in order to be able to switch BLAS and LAPACK
+implementations at runtime. If using this to build NumPy itself, it is
+recommended to also define NPY_CBLAS_LIBS (assuming your BLAS library has a
+CBLAS interface) to enable CBLAS usage for matrix multiplication (unoptimized
+otherwise).
+
 Example:
 ----------
 [DEFAULT]
@@ -1845,6 +1858,16 @@ class lapack_opt_info(system_info):
             return True
         return False
 
+    def _calc_info_from_envvar(self):
+        info = {}
+        info['language'] = 'f77'
+        info['libraries'] = []
+        info['include_dirs'] = []
+        info['define_macros'] = []
+        info['extra_link_args'] = os.environ['NPY_LAPACK_LIBS'].split()
+        self.set_info(**info)
+        return True
+
     def _calc_info(self, name):
         return getattr(self, '_calc_info_{}'.format(name))()
 
@@ -1855,6 +1878,12 @@ class lapack_opt_info(system_info):
                              "LAPACK order has unacceptable "
                              "values: {}".format(unknown_order))
 
+        if 'NPY_LAPACK_LIBS' in os.environ:
+            # Bypass autodetection, set language to F77 and use env var linker
+            # flags directly
+            self._calc_info_from_envvar()
+            return
+
         for lapack in lapack_order:
             if self._calc_info(lapack):
                 return
@@ -1977,6 +2006,20 @@ class blas_opt_info(system_info):
         self.set_info(**info)
         return True
 
+    def _calc_info_from_envvar(self):
+        info = {}
+        info['language'] = 'f77'
+        info['libraries'] = []
+        info['include_dirs'] = []
+        info['define_macros'] = []
+        info['extra_link_args'] = os.environ['NPY_BLAS_LIBS'].split()
+        if 'NPY_CBLAS_LIBS' in os.environ:
+            info['define_macros'].append(('HAVE_CBLAS', None))
+            info['extra_link_args'].extend(
+                                        os.environ['NPY_CBLAS_LIBS'].split())
+        self.set_info(**info)
+        return True
+
     def _calc_info(self, name):
         return getattr(self, '_calc_info_{}'.format(name))()
 
@@ -1985,6 +2028,12 @@ class blas_opt_info(system_info):
         if len(unknown_order) > 0:
             raise ValueError("blas_opt_info user defined BLAS order has unacceptable values: {}".format(unknown_order))
 
+        if 'NPY_BLAS_LIBS' in os.environ:
+            # Bypass autodetection, set language to F77 and use env var linker
+            # flags directly
+            self._calc_info_from_envvar()
+            return
+
         for blas in blas_order:
             if self._calc_info(blas):
                 return
