$NetBSD: patch-setup.py,v 1.10 2017/01/29 12:46:45 adam Exp $

* Prevent to detect optional tkinter.
* Disable demo programs.

--- setup.py.orig	2017-01-02 11:47:11.000000000 +0000
+++ setup.py
@@ -99,11 +99,7 @@ def _read(file):
         return fp.read()
 
 
-try:
-    import _tkinter
-except (ImportError, OSError):
-    # pypy emits an oserror
-    _tkinter = None
+_tkinter = None
 
 NAME = 'Pillow'
 PILLOW_VERSION = '4.0.0'
@@ -771,7 +767,6 @@ try:
           ext_modules=[Extension("PIL._imaging", ["_imaging.c"])],
           include_package_data=True,
           packages=find_packages(),
-          scripts=glob.glob("Scripts/*.py"),
           install_requires=['olefile'],
           test_suite='nose.collector',
           keywords=["Imaging", ],
