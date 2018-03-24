$NetBSD: patch-bindings_python_capstone_____init____.py,v 1.1 2018/03/24 17:10:42 joerg Exp $

--- bindings/python/capstone/__init__.py.orig	2017-03-02 14:21:24.000000000 +0000
+++ bindings/python/capstone/__init__.py
@@ -214,7 +214,7 @@ else:
 _found = False
 
 def _load_lib(path):
-    lib_file = join(path, _lib)
+    lib_file = join(sys.prefix, 'lib', _lib)
     try:
         return ctypes.cdll.LoadLibrary(lib_file)
     except OSError:
