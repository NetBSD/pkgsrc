$NetBSD: patch-bindings_python_capstone_____init____.py,v 1.3 2026/06/11 07:23:26 wiz Exp $

--- bindings/python/capstone/__init__.py.orig	2026-05-28 15:32:54.000000000 +0000
+++ bindings/python/capstone/__init__.py
@@ -373,7 +373,7 @@ def _load_lib(path):
 _found = False
 
 def _load_lib(path):
-    lib_file = join(path, _lib)
+    lib_file = join(sys.prefix, 'lib', _lib)
     if os.path.exists(lib_file):
         return ctypes.CDLL(lib_file, mode=mode)
     else:
