$NetBSD: patch-setup.py,v 1.6 2022/09/16 13:00:15 adam Exp $

Relax restrictions.
Use system libuv (--use-system-libuv option does not work for 'install').

--- setup.py.orig	2022-09-14 14:53:41.000000000 +0000
+++ setup.py
@@ -25,15 +25,11 @@ CYTHON_DEPENDENCY = 'Cython(>=0.29.32,<0
 
 # Minimal dependencies required to test uvloop.
 TEST_DEPENDENCIES = [
-    # pycodestyle is a dependency of flake8, but it must be frozen because
-    # their combination breaks too often
-    # (example breakage: https://gitlab.com/pycqa/flake8/issues/427)
     # aiohttp doesn't support 3.11 yet,
     # see https://github.com/aio-libs/aiohttp/issues/6600
     'aiohttp ; python_version < "3.11"',
     'flake8~=3.9.2',
     'psutil',
-    'pycodestyle~=2.7.0',
     'pyOpenSSL~=22.0.0',
     'mypy>=0.800',
     CYTHON_DEPENDENCY,
@@ -118,7 +114,7 @@ class uvloop_build_ext(build_ext):
 
     def initialize_options(self):
         super().initialize_options()
-        self.use_system_libuv = False
+        self.use_system_libuv = True
         self.cython_always = False
         self.cython_annotate = None
         self.cython_directives = None
