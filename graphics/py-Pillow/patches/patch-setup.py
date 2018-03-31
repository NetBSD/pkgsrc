$NetBSD: patch-setup.py,v 1.15 2018/03/31 16:22:11 adam Exp $

Prevent to detect optional tkinter.
Disable mp_compile hack; it has problems with native parallel building.

--- setup.py.orig	2018-01-01 21:04:32.000000000 +0000
+++ setup.py
@@ -23,7 +23,6 @@ from setuptools import Extension, setup
 
 # monkey patch import hook. Even though flake8 says it's not used, it is.
 # comment this out to disable multi threaded builds.
-import mp_compile
 
 
 if sys.platform == "win32" and sys.version_info >= (3, 7):
@@ -128,11 +128,7 @@ def get_version():
     return locals()['__version__']
 
 
-try:
-    import _tkinter
-except (ImportError, OSError):
-    # pypy emits an oserror
-    _tkinter = None
+_tkinter = None
 
 NAME = 'Pillow'
 PILLOW_VERSION = get_version()
