$NetBSD: patch-bindings_python_capstone_____init____.py,v 1.2 2020/08/18 20:20:46 riastradh Exp $

--- bindings/python/capstone/__init__.py.orig	2020-05-08 10:03:30.000000000 +0000
+++ bindings/python/capstone/__init__.py
@@ -280,7 +280,7 @@ else:
 _found = False
 
 def _load_lib(path):
-    lib_file = join(path, _lib)
+    lib_file = join(sys.prefix, 'lib', _lib)
     if os.path.exists(lib_file):
         return ctypes.cdll.LoadLibrary(lib_file)
     else:
