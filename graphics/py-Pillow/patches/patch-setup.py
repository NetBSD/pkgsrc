$NetBSD: patch-setup.py,v 1.27 2025/04/13 08:51:00 wiz Exp $

Do not look for xcb.

--- setup.py.orig	2025-04-12 17:02:40.000000000 +0000
+++ setup.py
@@ -844,11 +844,6 @@ class pil_build_ext(build_ext):
                         feature.set("webp", prefix + "webp")
                         break
 
-        if feature.want("xcb"):
-            _dbg("Looking for xcb")
-            if _find_include_file(self, "xcb/xcb.h"):
-                if _find_library_file(self, "xcb"):
-                    feature.set("xcb", "xcb")
 
         if feature.want("avif"):
             _dbg("Looking for avif")
