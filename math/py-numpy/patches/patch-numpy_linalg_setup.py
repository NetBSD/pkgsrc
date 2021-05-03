$NetBSD: patch-numpy_linalg_setup.py,v 1.1 2021/05/03 17:15:22 adam Exp $

Use C language (not F77 from lapack_info); fixes library name on Darwin.

--- numpy/linalg/setup.py.orig	2021-04-22 17:45:05.000000000 +0000
+++ numpy/linalg/setup.py
@@ -54,6 +54,8 @@ def configuration(parent_package='', top
                 self.set_info(**info)
 
         lapack_info = numpy_linalg_lapack_lite().get_info(2)
+    else:
+        lapack_info['language'] = 'c'
 
     def get_lapack_lite_sources(ext, build_dir):
         if use_lapack_lite:
