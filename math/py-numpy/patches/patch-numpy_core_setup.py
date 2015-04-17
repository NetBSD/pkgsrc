$NetBSD: patch-numpy_core_setup.py,v 1.2 2015/04/17 00:41:38 wen Exp $
Do not require Atlas to make 'dotblas' module; libblas should be sufficient.
--- numpy/core/setup.py.orig	2015-02-01 16:38:25.000000000 +0000
+++ numpy/core/setup.py
@@ -953,8 +953,6 @@ def configuration(parent_package='',top_
     #blas_info = {}
     def get_dotblas_sources(ext, build_dir):
         if blas_info:
-            if ('NO_ATLAS_INFO', 1) in blas_info.get('define_macros', []):
-                return None # dotblas needs ATLAS, Fortran compiled blas will not be sufficient.
             return ext.depends[:3]
         return None # no extension module will be built
 
