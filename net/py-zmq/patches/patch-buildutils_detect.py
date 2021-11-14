$NetBSD: patch-buildutils_detect.py,v 1.3 2021/11/14 20:17:08 adam Exp $

Let compiler decide what's best.

--- buildutils/detect.py.orig	2021-09-16 07:32:51.000000000 +0000
+++ buildutils/detect.py
@@ -49,11 +49,6 @@ def test_compilation(cfile, compiler=Non
         else:
             # allow for missing UB arch, since it will still work:
             lpreargs = ['-undefined', 'dynamic_lookup']
-    if sys.platform == 'sunos5':
-        if platform.architecture()[0] == '32bit':
-            lpreargs = ['-m32']
-        else:
-            lpreargs = ['-m64']
     extra = compiler_attrs.get('extra_compile_args', None)
     extra_link = compiler_attrs.get('extra_link_args', [])
     lpreargs.extend(extra_link)
