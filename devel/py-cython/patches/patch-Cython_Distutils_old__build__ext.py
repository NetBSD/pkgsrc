$NetBSD: patch-Cython_Distutils_old__build__ext.py,v 1.1 2019/12/11 20:20:23 adam Exp $

Revert to Cython 0.29.13 version of this file to fix PR/54712.

--- Cython/Distutils/old_build_ext.py.orig	2019-12-11 20:04:08.000000000 +0000
+++ Cython/Distutils/old_build_ext.py
@@ -191,8 +191,7 @@ class old_build_ext(_build_ext.build_ext
 
         for ext in self.extensions:
             ext.sources = self.cython_sources(ext.sources, ext)
-        # Call original build_extensions
-        _build_ext.build_ext.build_extensions(self)
+            self.build_extension(ext)
 
     def cython_sources(self, sources, extension):
         """
