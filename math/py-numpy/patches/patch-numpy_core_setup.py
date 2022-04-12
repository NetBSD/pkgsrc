$NetBSD: patch-numpy_core_setup.py,v 1.6 2022/04/12 11:50:34 tnn Exp $

Use C language (not F77 from blas_info); fixes library name on Darwin.

Don't redefine -D__STDC_VERSION__=0 on the command line. It is almost
certainly the wrong thing to do and breaks the build completely on
modern SunOS.

--- numpy/core/setup.py.orig	2022-03-06 17:04:34.000000000 +0000
+++ numpy/core/setup.py
@@ -816,6 +816,7 @@ def configuration(parent_package='',top_
 
     if have_blas:
         extra_info = blas_info
+        extra_info['language'] = 'c'
         # These files are also in MANIFEST.in so that they are always in
         # the source distribution independently of HAVE_CBLAS.
         common_src.extend([join('src', 'common', 'cblasfuncs.c'),
@@ -1038,7 +1039,6 @@ def configuration(parent_package='',top_
                          extra_objects=svml_objs,
                          extra_info=extra_info,
                          extra_cxx_compile_args=['-std=c++11',
-                                                 '-D__STDC_VERSION__=0',
                                                  '-fno-exceptions',
                                                  '-fno-rtti'])
 
