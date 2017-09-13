$NetBSD: patch-setup.py,v 1.2 2017/09/13 06:21:02 adam Exp $

Use external libuv.

--- setup.py.orig	2017-09-12 20:04:48.000000000 +0000
+++ setup.py
@@ -80,7 +80,7 @@ class uvloop_build_ext(build_ext):
             return
 
         super().initialize_options()
-        self.use_system_libuv = False
+        self.use_system_libuv = True
         self.cython_always = False
         self.cython_annotate = None
         self.cython_directives = None
