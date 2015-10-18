$NetBSD: patch-setup.py,v 1.5 2015/10/18 15:47:10 adam Exp $

* Prevent to detect optional tkinter.
* Disable demo programs.

--- setup.py.orig	2015-10-01 15:27:21.000000000 +0000
+++ setup.py
@@ -82,11 +82,7 @@ def _lib_include(root):
 def _read(file):
     return open(file, 'rb').read()
 
-try:
-    import _tkinter
-except (ImportError, OSError):
-    # pypy emits an oserror
-    _tkinter = None
+_tkinter = None
 
 
 NAME = 'Pillow'
@@ -760,7 +756,6 @@ setup(
     ext_modules=[Extension("PIL._imaging", ["_imaging.c"])],
     include_package_data=True,
     packages=find_packages(),
-    scripts=glob.glob("Scripts/*.py"),
     test_suite='nose.collector',
     keywords=["Imaging", ],
     license='Standard PIL License',
