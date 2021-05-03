$NetBSD: patch-numpy_core_setup.py,v 1.5 2021/05/03 17:15:22 adam Exp $

Use C language (not F77 from blas_info); fixes library name on Darwin.

--- numpy/core/setup.py.orig	2021-04-22 17:50:58.000000000 +0000
+++ numpy/core/setup.py
@@ -760,6 +760,7 @@ def configuration(parent_package='',top_
 
     if have_blas:
         extra_info = blas_info
+        extra_info['language'] = 'c'
         # These files are also in MANIFEST.in so that they are always in
         # the source distribution independently of HAVE_CBLAS.
         common_src.extend([join('src', 'common', 'cblasfuncs.c'),
