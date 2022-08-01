$NetBSD: patch-setup.py,v 1.24 2022/08/01 14:51:15 wiz Exp $

Fix finding zlib.h.

--- setup.py.orig	2022-07-01 13:14:51.000000000 +0000
+++ setup.py
@@ -636,7 +636,9 @@ class pil_build_ext(build_ext):
 
         if feature.want("zlib"):
             _dbg("Looking for zlib")
-            if _find_include_file(self, "zlib.h"):
+            if True:
+                feature.zlib = "z"
+            elif _find_include_file(self, "zlib.h"):
                 if _find_library_file(self, "z"):
                     feature.zlib = "z"
                 elif sys.platform == "win32" and _find_library_file(self, "zlib"):
