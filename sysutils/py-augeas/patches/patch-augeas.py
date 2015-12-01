$NetBSD: patch-augeas.py,v 1.1 2015/12/01 13:04:54 fhajny Exp $

Simplify the way to look up and load the native lib, as
find_library is unreliable on NetBSD and SunOS at least.
--- augeas.py.orig	2014-08-31 16:44:49.000000000 +0000
+++ augeas.py
@@ -41,7 +41,7 @@ Nils Philippsen <nils@redhat.com>
 import types
 import ctypes
 import ctypes.util
-from sys import version_info as _pyver
+from sys import platform, version_info as _pyver
 from functools import reduce
 
 
@@ -65,12 +65,15 @@ def dec(st):
         return st.decode(AUGENC)
 
 
-def _dlopen(*args):
+def _dlopen(args):
     """Search for one of the libraries given as arguments and load it.
     Returns the library.
     """
-    libs = [l for l in [ ctypes.util.find_library(a) for a in args ] if l]
-    lib  = reduce(lambda x, y: x or ctypes.cdll.LoadLibrary(y), libs, None)
+    if platform == "darwin":
+        libname = "lib" + args + ".dylib"
+    else:
+        libname = "lib" + args + ".so"
+    lib = ctypes.cdll.LoadLibrary(libname)
     if not lib:
         raise ImportError("Unable to import lib%s!" % args[0])
     return lib
