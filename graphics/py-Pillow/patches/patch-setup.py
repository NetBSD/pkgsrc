$NetBSD: patch-setup.py,v 1.22 2019/11/20 23:34:36 minskim Exp $

Disable mp_compile hack; it has problems with native parallel building.

--- setup.py.orig	2019-10-20 09:47:22.000000000 +0000
+++ setup.py
@@ -22,7 +22,6 @@ from setuptools import Extension, setup
 
 # monkey patch import hook. Even though flake8 says it's not used, it is.
 # comment this out to disable multi threaded builds.
-import mp_compile
 
 if sys.platform == "win32" and sys.version_info >= (3, 9):
     warnings.warn(
@@ -332,12 +331,6 @@ class pil_build_ext(build_ext):
         if self.debug:
             global DEBUG
             DEBUG = True
-        if sys.version_info.major >= 3 and not self.parallel:
-            # For Python 2.7, we monkeypatch distutils to have parallel
-            # builds. If --parallel (or -j) wasn't specified, we want to
-            # reproduce the same behavior as before, that is, auto-detect the
-            # number of jobs.
-            self.parallel = mp_compile.MAX_PROCS
         for x in self.feature:
             if getattr(self, "disable_%s" % x):
                 setattr(self.feature, x, False)
@@ -539,7 +532,7 @@ class pil_build_ext(build_ext):
 
         if feature.want("zlib"):
             _dbg("Looking for zlib")
-            if _find_include_file(self, "zlib.h"):
+            if True or _find_include_file(self, "zlib.h"):
                 if _find_library_file(self, "z"):
                     feature.zlib = "z"
                 elif sys.platform == "win32" and _find_library_file(self, "zlib"):
