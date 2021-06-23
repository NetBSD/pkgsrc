$NetBSD: patch-Lib_ctypes_macholib_dyld.py,v 1.1 2021/06/23 18:30:24 schmonz Exp $

darwin20 support, via MacPorts.

--- Lib/ctypes/macholib/dyld.py.orig	2021-06-22 19:20:28.000000000 +0000
+++ Lib/ctypes/macholib/dyld.py
@@ -7,6 +7,12 @@ from framework import framework_info
 from dylib import dylib_info
 from itertools import *
 
+try:
+    from _ctypes import _dyld_shared_cache_contains_path
+except ImportError:
+    def _dyld_shared_cache_contains_path(*args):
+        raise NotImplementedError
+
 __all__ = [
     'dyld_find', 'framework_find',
     'framework_info', 'dylib_info',
@@ -132,6 +138,12 @@ def dyld_find(name, executable_path=None
             ), env):
         if os.path.isfile(path):
             return path
+        try:
+            if _dyld_shared_cache_contains_path(path):
+                return path
+        except NotImplementedError:
+            pass
+
     raise ValueError("dylib %s could not be found" % (name,))
 
 def framework_find(fn, executable_path=None, env=None):
