$NetBSD: patch-numpy_core_setup.py,v 1.9 2022/05/25 19:09:25 tnn Exp $

Use C language (not F77 from blas_info); fixes library name on Darwin.
Add configure test for HAVE_XLOCALE_H, used by numpyos.c.

--- numpy/core/setup.py.orig	2022-05-20 05:46:10.000000000 +0000
+++ numpy/core/setup.py
@@ -208,6 +208,9 @@ def check_math_capabilities(config, ext,
         # It didn't work with xlocale.h, maybe it will work with locale.h?
         locale_headers[1] = "locale.h"
         check_funcs(OPTIONAL_LOCALE_FUNCS, headers=locale_headers)
+    st = config.check_header('xlocale.h')
+    if st:
+        moredefs.append(('HAVE_XLOCALE_H', 1))
 
     for tup in OPTIONAL_INTRINSICS:
         headers = None
@@ -217,7 +220,7 @@ def check_math_capabilities(config, ext,
             f, args, headers, m = tup[0], tup[1], [tup[2]], fname2def(tup[0])
         else:
             f, args, headers, m = tup[0], tup[1], [tup[2]], fname2def(tup[3])
-        if config.check_func(f, decl=False, call=True, call_args=args,
+        if config.check_func(f, decl=False, call=False, call_args=args,
                              headers=headers):
             moredefs.append((m, 1))
 
@@ -868,6 +871,7 @@ def configuration(parent_package='',top_
 
     if have_blas:
         extra_info = blas_info
+        extra_info['language'] = 'c'
         # These files are also in MANIFEST.in so that they are always in
         # the source distribution independently of HAVE_CBLAS.
         common_src.extend([join('src', 'common', 'cblasfuncs.c'),
