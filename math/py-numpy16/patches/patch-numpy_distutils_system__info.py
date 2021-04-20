$NetBSD: patch-numpy_distutils_system__info.py,v 1.3 2021/04/20 20:58:39 thor Exp $

--- numpy/distutils/system_info.py.orig	2021-04-20 20:11:02.731971594 +0000
+++ numpy/distutils/system_info.py
@@ -82,6 +82,19 @@ The order of finding the locations of re
  3. ALL section in site.cfg
 Only the first complete match is returned.
 
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
 [ALL]
@@ -1542,8 +1555,24 @@ class lapack_opt_info(system_info):
 
     notfounderror = LapackNotFoundError
 
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
     def calc_info(self):
 
+        if 'NPY_LAPACK_LIBS' in os.environ:
+            # Bypass autodetection, set language to F77 and use env var linker
+            # flags directly
+            self._calc_info_from_envvar()
+            return
+
         lapack_mkl_info = get_info('lapack_mkl')
         if lapack_mkl_info:
             self.set_info(**lapack_mkl_info)
@@ -1621,8 +1650,28 @@ class blas_opt_info(system_info):
 
     notfounderror = BlasNotFoundError
 
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
     def calc_info(self):
 
+        if 'NPY_BLAS_LIBS' in os.environ:
+            # Bypass autodetection, set language to F77 and use env var linker
+            # flags directly
+            self._calc_info_from_envvar()
+            return
+
         blas_mkl_info = get_info('blas_mkl')
         if blas_mkl_info:
             self.set_info(**blas_mkl_info)
