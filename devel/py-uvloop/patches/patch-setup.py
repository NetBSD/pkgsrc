$NetBSD: patch-setup.py,v 1.1 2017/06/24 06:47:59 adam Exp $

Use external libuv.

--- setup.py.orig	2017-06-24 06:13:59.000000000 +0000
+++ setup.py
@@ -81,7 +81,7 @@ class uvloop_build_ext(build_ext):
 
     def initialize_options(self):
         super().initialize_options()
-        self.use_system_libuv = False
+        self.use_system_libuv = True
         self.cython_always = False
         self.cython_annotate = None
         self.cython_directives = None
