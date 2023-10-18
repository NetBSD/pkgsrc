$NetBSD: patch-setup.py,v 1.7 2023/10/18 08:57:11 adam Exp $

Use system libuv (--use-system-libuv option does not work for 'install').

--- setup.py.orig	2023-10-13 15:49:42.000000000 +0000
+++ setup.py
@@ -83,7 +83,7 @@ class uvloop_build_ext(build_ext):
 
     def initialize_options(self):
         super().initialize_options()
-        self.use_system_libuv = False
+        self.use_system_libuv = True
         self.cython_always = False
         self.cython_annotate = None
         self.cython_directives = None
