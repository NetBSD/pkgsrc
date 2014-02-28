$NetBSD: patch-numpy_core_setup.py,v 1.1 2014/02/28 09:43:11 adam Exp $

Do not require Atlas to make 'dotblas' module; libblas should be sufficient.

--- numpy/core/setup.py.orig	2014-02-28 09:14:32.000000000 +0000
+++ numpy/core/setup.py
@@ -929,8 +929,6 @@ def configuration(parent_package='',top_
     #blas_info = {}
     def get_dotblas_sources(ext, build_dir):
         if blas_info:
-            if ('NO_ATLAS_INFO', 1) in blas_info.get('define_macros', []):
-                return None # dotblas needs ATLAS, Fortran compiled blas will not be sufficient.
             return ext.depends[:1]
         return None # no extension module will be built
 
