$NetBSD: patch-numpy_distutils_system__info.py,v 1.7 2021/04/20 20:53:49 thor Exp $

--- numpy/distutils/system_info.py.orig	2021-04-20 18:13:28.992593008 +0000
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
@@ -1744,6 +1757,16 @@ class lapack_opt_info(system_info):
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
 
@@ -1767,6 +1790,12 @@ class lapack_opt_info(system_info):
                                  "LAPACK order has unacceptable "
                                  "values: {}".format(non_existing))
 
+        if 'NPY_LAPACK_LIBS' in os.environ:
+            # Bypass autodetection, set language to F77 and use env var linker
+            # flags directly
+            self._calc_info_from_envvar()
+            return
+
         for lapack in lapack_order:
             if self._calc_info(lapack):
                 return
@@ -1889,6 +1918,20 @@ class blas_opt_info(system_info):
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
 
@@ -1910,6 +1953,12 @@ class blas_opt_info(system_info):
             if len(non_existing) > 0:
                 raise ValueError("blas_opt_info user defined BLAS order has unacceptable values: {}".format(non_existing))
 
+        if 'NPY_BLAS_LIBS' in os.environ:
+            # Bypass autodetection, set language to F77 and use env var linker
+            # flags directly
+            self._calc_info_from_envvar()
+            return
+
         for blas in blas_order:
             if self._calc_info(blas):
                 return
