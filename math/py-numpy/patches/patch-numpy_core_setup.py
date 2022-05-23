$NetBSD: patch-numpy_core_setup.py,v 1.8 2022/05/23 17:28:41 ryoon Exp $

Use C language (not F77 from blas_info); fixes library name on Darwin.

--- numpy/core/setup.py.orig	2022-05-19 22:46:10.000000000 +0000
+++ numpy/core/setup.py
@@ -217,7 +217,7 @@ def check_math_capabilities(config, ext,
             f, args, headers, m = tup[0], tup[1], [tup[2]], fname2def(tup[0])
         else:
             f, args, headers, m = tup[0], tup[1], [tup[2]], fname2def(tup[3])
-        if config.check_func(f, decl=False, call=True, call_args=args,
+        if config.check_func(f, decl=False, call=False, call_args=args,
                              headers=headers):
             moredefs.append((m, 1))
 
@@ -868,6 +868,7 @@ def configuration(parent_package='',top_
 
     if have_blas:
         extra_info = blas_info
+        extra_info['language'] = 'c'
         # These files are also in MANIFEST.in so that they are always in
         # the source distribution independently of HAVE_CBLAS.
         common_src.extend([join('src', 'common', 'cblasfuncs.c'),
