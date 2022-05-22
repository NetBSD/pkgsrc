$NetBSD: patch-numpy_core_setup.py,v 1.7 2022/05/22 19:14:00 adam Exp $

Use C language (not F77 from blas_info); fixes library name on Darwin.

--- numpy/core/setup.py.orig	2022-05-20 05:46:10.000000000 +0000
+++ numpy/core/setup.py
@@ -868,6 +868,7 @@ def configuration(parent_package='',top_
 
     if have_blas:
         extra_info = blas_info
+        extra_info['language'] = 'c'
         # These files are also in MANIFEST.in so that they are always in
         # the source distribution independently of HAVE_CBLAS.
         common_src.extend([join('src', 'common', 'cblasfuncs.c'),
