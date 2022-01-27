$NetBSD: patch-setup.py,v 1.5 2022/01/27 10:06:38 wiz Exp $

Relax restrictions.
Use system libuv (--use-system-libuv option does not work for 'install').

--- setup.py.orig	2021-08-10 19:05:35.000000000 +0000
+++ setup.py
@@ -25,13 +25,9 @@ CYTHON_DEPENDENCY = 'Cython(>=0.29.24,<0
 
 # Minimal dependencies required to test uvloop.
 TEST_DEPENDENCIES = [
-    # pycodestyle is a dependency of flake8, but it must be frozen because
-    # their combination breaks too often
-    # (example breakage: https://gitlab.com/pycqa/flake8/issues/427)
     'aiohttp',
     'flake8~=3.9.2',
     'psutil',
-    'pycodestyle~=2.7.0',
     'pyOpenSSL~=19.0.0',
     'mypy>=0.800',
 ]
@@ -121,7 +117,7 @@ class uvloop_build_ext(build_ext):
             return
 
         super().initialize_options()
-        self.use_system_libuv = False
+        self.use_system_libuv = True
         self.cython_always = False
         self.cython_annotate = None
         self.cython_directives = None
