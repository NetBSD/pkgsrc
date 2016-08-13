$NetBSD: patch-setup.py,v 1.7 2016/08/13 08:07:22 wen Exp $

* Prevent to detect optional tkinter.
* Disable demo programs.

--- setup.py.orig	2016-08-13 07:58:03.000000000 +0000
+++ setup.py
@@ -103,11 +103,7 @@ def _read(file):
     return open(file, 'rb').read()
 
 
-try:
-    import _tkinter
-except (ImportError, OSError):
-    # pypy emits an oserror
-    _tkinter = None
+_tkinter = None
 
 NAME = 'Pillow'
 PILLOW_VERSION = '3.3.0'
@@ -746,7 +742,6 @@ setup(name=NAME,
       ext_modules=[Extension("PIL._imaging", ["_imaging.c"])],
       include_package_data=True,
       packages=find_packages(),
-      scripts=glob.glob("Scripts/*.py"),
       test_suite='nose.collector',
       keywords=["Imaging", ],
       license='Standard PIL License',
