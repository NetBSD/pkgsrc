$NetBSD: patch-buildutils_detect.py,v 1.1 2017/02/02 11:53:58 fhajny Exp $

Let compiler decide what's best.

--- buildutils/detect.py.orig	2016-11-22 12:41:00.000000000 +0000
+++ buildutils/detect.py
@@ -47,11 +47,6 @@ def test_compilation(cfile, compiler=Non
         else:
             # allow for missing UB arch, since it will still work:
             lpreargs = ['-undefined', 'dynamic_lookup']
-    if sys.platform == 'sunos5':
-        if platform.architecture()[0]=='32bit':
-            lpreargs = ['-m32']
-        else: 
-            lpreargs = ['-m64']
     extra = compiler_attrs.get('extra_compile_args', None)
 
     objs = cc.compile([cfile], extra_preargs=cpreargs, extra_postargs=extra)
