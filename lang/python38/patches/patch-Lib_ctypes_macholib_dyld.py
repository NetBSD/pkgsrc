$NetBSD: patch-Lib_ctypes_macholib_dyld.py,v 1.1 2020/11/17 19:33:15 sjmulder Exp $

Support for macOS 11 and Apple Silicon (ARM). Mostly backported from:
https://github.com/python/cpython/pull/22855

--- Lib/ctypes/macholib/dyld.py.orig	2020-09-23 12:36:32.000000000 +0000
+++ Lib/ctypes/macholib/dyld.py
@@ -6,6 +6,11 @@ import os
 from ctypes.macholib.framework import framework_info
 from ctypes.macholib.dylib import dylib_info
 from itertools import *
+try:
+    from _ctypes import _dyld_shared_cache_contains_path
+except ImportError:
+    def _dyld_shared_cache_contains_path(*args):
+        raise NotImplementedError
 
 __all__ = [
     'dyld_find', 'framework_find',
@@ -122,8 +127,15 @@ def dyld_find(name, executable_path=None
                 dyld_executable_path_search(name, executable_path),
                 dyld_default_search(name, env),
             ), env):
+
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
