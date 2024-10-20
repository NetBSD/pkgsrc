$NetBSD: patch-setup.py,v 1.26 2024/10/20 20:05:35 adam Exp $

Do not look for xcb.

--- setup.py.orig	2024-10-15 05:58:32.000000000 +0000
+++ setup.py
@@ -833,11 +833,6 @@ class pil_build_ext(build_ext):
                         feature.set("webp", prefix + "webp")
                         break
 
-        if feature.want("xcb"):
-            _dbg("Looking for xcb")
-            if _find_include_file(self, "xcb/xcb.h"):
-                if _find_library_file(self, "xcb"):
-                    feature.set("xcb", "xcb")
 
         for f in feature:
             if not feature.get(f) and feature.require(f):
