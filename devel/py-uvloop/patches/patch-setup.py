$NetBSD: patch-setup.py,v 1.4 2019/09/25 08:45:54 adam Exp $

Use system libuv (--use-system-libuv option does not work for 'install').

--- setup.py.orig	2019-09-25 08:40:47.000000000 +0000
+++ setup.py
@@ -87,7 +87,7 @@ class uvloop_build_ext(build_ext):
             return
 
         super().initialize_options()
-        self.use_system_libuv = False
+        self.use_system_libuv = True
         self.cython_always = False
         self.cython_annotate = None
         self.cython_directives = None
