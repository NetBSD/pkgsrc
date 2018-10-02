$NetBSD: patch-setup.py,v 1.17 2018/10/02 09:10:46 adam Exp $

Disable mp_compile hack; it has problems with native parallel building.
Prevent to detect optional tkinter.

--- setup.py.orig	2018-10-01 05:51:22.000000000 +0000
+++ setup.py
@@ -23,7 +23,6 @@ from setuptools import Extension, setup
 
 # monkey patch import hook. Even though flake8 says it's not used, it is.
 # comment this out to disable multi threaded builds.
-import mp_compile
 
 
 if sys.platform == "win32" and sys.version_info >= (3, 8):
@@ -128,11 +127,7 @@ def get_version():
     return locals()['__version__']
 
 
-try:
-    import _tkinter
-except (ImportError, OSError):
-    # pypy emits an oserror
-    _tkinter = None
+_tkinter = None
 
 NAME = 'Pillow'
 PILLOW_VERSION = get_version()
@@ -205,12 +200,6 @@ class pil_build_ext(build_ext):
         if self.debug:
             global DEBUG
             DEBUG = True
-        if sys.version_info >= (3, 5) and not self.parallel:
-            # For Python < 3.5, we monkeypatch distutils to have parallel
-            # builds. If --parallel (or -j) wasn't specified, we want to
-            # reproduce the same behavior as before, that is, auto-detect the
-            # number of jobs.
-            self.parallel = mp_compile.MAX_PROCS
         for x in self.feature:
             if getattr(self, 'disable_%s' % x):
                 setattr(self.feature, x, False)
