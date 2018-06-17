$NetBSD: patch-Lib_ctypes_util.py,v 1.1 2018/06/17 19:21:22 adam Exp $

Look for shared libraries in PkgSrc prefix.
Note: /usr/local will get replaced by SUBST.

--- Lib/ctypes/util.py.orig	2018-03-28 09:19:31.000000000 +0000
+++ Lib/ctypes/util.py
@@ -278,7 +278,7 @@ elif os.name == "posix":
         def _findLib_ld(name):
             # See issue #9998 for why this is needed
             expr = r'[^\(\)\s]*lib%s\.[^\(\)\s]*' % re.escape(name)
-            cmd = ['ld', '-t']
+            cmd = ['ld', '-t', '-L', '/usr/local/lib']
             libpath = os.environ.get('LD_LIBRARY_PATH')
             if libpath:
                 for d in libpath.split(':'):
