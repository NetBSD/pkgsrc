$NetBSD: patch-cairocffi_____init____.py,v 1.1 2018/07/18 00:24:30 joerg Exp $

--- cairocffi/__init__.py.orig	2017-02-03 11:41:24.000000000 +0000
+++ cairocffi/__init__.py
@@ -12,6 +12,7 @@
 
 import sys
 import ctypes.util
+import sysconfig
 
 from . import constants
 from .compat import FileNotFoundError
@@ -25,6 +26,18 @@ version_info = (1, 10, 0)
 
 def dlopen(ffi, *names):
     """Try various names for the same library, for different platforms."""
+    # First pass: try to dlopen the shared library directly.
+    # This may fail on systems where SHLIB_SUFFIX is broken like OSX.
+    suffix = sysconfig.get_config_var('SHLIB_SUFFIX') or sysconfig.get_config_var('SHLIB_EXT')
+    for name in names:
+        for lib_name in [name, 'lib' + name]:
+            try:
+                lib = ffi.dlopen(lib_name + suffix)
+                if lib:
+                    return lib
+            except OSError:
+                pass
+    # Second pass: try to use ctypes as fallback.
     for name in names:
         for lib_name in [name, 'lib' + name]:
             try:
