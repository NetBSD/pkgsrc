$NetBSD: patch-numpy_distutils_system__info.py,v 1.5 2021/03/26 20:34:28 thor Exp $

Disable openblas detection.  In pkgsrc, use mk/blas.buildlink.mk.

--- numpy/distutils/system_info.py.orig	2020-06-02 05:24:58.000000000 +0000
+++ numpy/distutils/system_info.py
@@ -1730,34 +1722,18 @@ class lapack_opt_info(system_info):
         return getattr(self, '_calc_info_{}'.format(name))()
 
     def calc_info(self):
-        user_order = os.environ.get(self.order_env_var_name, None)
-        if user_order is None:
-            lapack_order = self.lapack_order
-        else:
-            # the user has requested the order of the
-            # check they are all in the available list, a COMMA SEPARATED list
-            user_order = user_order.lower().split(',')
-            non_existing = []
-            lapack_order = []
-            for order in user_order:
-                if order in self.lapack_order:
-                    lapack_order.append(order)
-                elif len(order) > 0:
-                    non_existing.append(order)
-            if len(non_existing) > 0:
-                raise ValueError("lapack_opt_info user defined "
-                                 "LAPACK order has unacceptable "
-                                 "values: {}".format(non_existing))
-
-        for lapack in lapack_order:
-            if self._calc_info(lapack):
-                return
-
-        if 'lapack' not in lapack_order:
-            # Since the user may request *not* to use any library, we still need
-            # to raise warnings to signal missing packages!
-            warnings.warn(LapackNotFoundError.__doc__ or '', stacklevel=2)
-            warnings.warn(LapackSrcNotFoundError.__doc__ or '', stacklevel=2)
+        # Fixing usage of LAPACK specified in LAPACK_LIBS.
+        # Existence of LAPACK_LIBS is mandatory. Things shall break early
+        # if it is not set.
+        info = {}
+        info['language'] = 'f77'
+        info['libraries'] = []
+        info['include_dirs'] = []
+        info['define_macros'] = []
+        info['extra_link_args'] = os.environ['LAPACK_LIBS'].split()
+ 
+        self.set_info(**info)
+        return
 
 
 class _ilp64_opt_info_mixin:
@@ -1875,32 +1848,22 @@ class blas_opt_info(system_info):
         return getattr(self, '_calc_info_{}'.format(name))()
 
     def calc_info(self):
-        user_order = os.environ.get(self.order_env_var_name, None)
-        if user_order is None:
-            blas_order = self.blas_order
-        else:
-            # the user has requested the order of the
-            # check they are all in the available list
-            user_order = user_order.lower().split(',')
-            non_existing = []
-            blas_order = []
-            for order in user_order:
-                if order in self.blas_order:
-                    blas_order.append(order)
-                elif len(order) > 0:
-                    non_existing.append(order)
-            if len(non_existing) > 0:
-                raise ValueError("blas_opt_info user defined BLAS order has unacceptable values: {}".format(non_existing))
-
-        for blas in blas_order:
-            if self._calc_info(blas):
-                return
-
-        if 'blas' not in blas_order:
-            # Since the user may request *not* to use any library, we still need
-            # to raise warnings to signal missing packages!
-            warnings.warn(BlasNotFoundError.__doc__ or '', stacklevel=2)
-            warnings.warn(BlasSrcNotFoundError.__doc__ or '', stacklevel=2)
+        # Fixing usage of libcblas and the BLAS specified in BLAS_LIBS.
+        # Existence of BLAS_LIBS is mandatory. Things shall break early
+        # if it is not set.
+        info = {}
+        # We assume a generic BLAS, which is a Fortran lib.
+        info['language'] = 'f77'
+        # Try to work without cblas, just link BLAS_LIBS.
+        #info['libraries'] = ['cblas']
+        #info['define_macros'] = [('HAVE_CBLAS', None)]
+        info['libraries'] = []
+        info['include_dirs'] = []
+        info['define_macros'] = []
+        info['extra_link_args'] = os.environ['BLAS_LIBS'].split()
+ 
+        self.set_info(**info)
+        return
 
 
 class blas_ilp64_opt_info(blas_opt_info, _ilp64_opt_info_mixin):
