$NetBSD: patch-setup.py,v 1.25 2024/01/05 23:47:53 adam Exp $

Fix finding zlib.h.
Do not look for xcb.

--- setup.py.orig	2024-01-02 08:28:43.000000000 +0000
+++ setup.py
@@ -642,7 +642,9 @@ class pil_build_ext(build_ext):
 
         if feature.want("zlib"):
             _dbg("Looking for zlib")
-            if _find_include_file(self, "zlib.h"):
+            if True:
+                feature.zlib = "z"
+            elif _find_include_file(self, "zlib.h"):
                 if _find_library_file(self, "z"):
                     feature.zlib = "z"
                 elif sys.platform == "win32" and _find_library_file(self, "zlib"):
@@ -800,11 +802,6 @@ class pil_build_ext(build_ext):
                 ):
                     feature.webpmux = "libwebpmux"
 
-        if feature.want("xcb"):
-            _dbg("Looking for xcb")
-            if _find_include_file(self, "xcb/xcb.h"):
-                if _find_library_file(self, "xcb"):
-                    feature.xcb = "xcb"
 
         for f in feature:
             if not getattr(feature, f) and feature.require(f):
