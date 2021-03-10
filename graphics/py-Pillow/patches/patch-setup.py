$NetBSD: patch-setup.py,v 1.23 2021/03/10 18:43:30 adam Exp $

Fix finding zlib.h.

--- setup.py.orig	2021-03-06 05:17:25.000000000 +0000
+++ setup.py
@@ -561,7 +561,7 @@ class pil_build_ext(build_ext):
 
         if feature.want("zlib"):
             _dbg("Looking for zlib")
-            if _find_include_file(self, "zlib.h"):
+            if True or _find_include_file(self, "zlib.h"):
                 if _find_library_file(self, "z"):
                     feature.zlib = "z"
                 elif sys.platform == "win32" and _find_library_file(self, "zlib"):
