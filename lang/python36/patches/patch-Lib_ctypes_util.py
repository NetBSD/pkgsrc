$NetBSD: patch-Lib_ctypes_util.py,v 1.2 2019/03/02 13:23:36 adam Exp $

Fallback to clang.

Look for shared libraries in PkgSrc prefix.
Note: /usr/local will get replaced by SUBST.

--- Lib/ctypes/util.py.orig	2018-12-23 21:37:14.000000000 +0000
+++ Lib/ctypes/util.py
@@ -93,6 +93,8 @@ elif os.name == "posix":
 
         c_compiler = shutil.which('gcc')
         if not c_compiler:
+            c_compiler = shutil.which('clang')
+        if not c_compiler:
             c_compiler = shutil.which('cc')
         if not c_compiler:
             # No C compiler available, give up
@@ -278,7 +280,7 @@ elif os.name == "posix":
         def _findLib_ld(name):
             # See issue #9998 for why this is needed
             expr = r'[^\(\)\s]*lib%s\.[^\(\)\s]*' % re.escape(name)
-            cmd = ['ld', '-t']
+            cmd = ['ld', '-t', '-L', '/usr/local/lib']
             libpath = os.environ.get('LD_LIBRARY_PATH')
             if libpath:
                 for d in libpath.split(':'):
