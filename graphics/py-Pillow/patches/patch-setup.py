$NetBSD: patch-setup.py,v 1.6 2016/04/21 08:13:50 leot Exp $

* Prevent to detect optional tkinter.
* Disable demo programs.

--- setup.py.orig	2016-04-01 13:10:57.000000000 +0000
+++ setup.py
@@ -80,12 +80,7 @@ def _lib_include(root):
 def _read(file):
     return open(file, 'rb').read()
 
-
-try:
-    import _tkinter
-except (ImportError, OSError):
-    # pypy emits an oserror
-    _tkinter = None
+_tkinter = None
 
 NAME = 'Pillow'
 PILLOW_VERSION = '3.2.0'
@@ -760,7 +755,6 @@ setup(name=NAME,
       ext_modules=[Extension("PIL._imaging", ["_imaging.c"])],
       include_package_data=True,
       packages=find_packages(),
-      scripts=glob.glob("Scripts/*.py"),
       test_suite='nose.collector',
       keywords=["Imaging", ],
       license='Standard PIL License',
