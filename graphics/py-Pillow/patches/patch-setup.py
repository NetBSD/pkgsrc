$NetBSD: patch-setup.py,v 1.9 2016/11/06 15:05:30 adam Exp $

* Prevent to detect optional tkinter.
* Disable demo programs.

--- setup.py.orig	2016-10-18 19:12:54.000000000 +0000
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
 PILLOW_VERSION = '3.4.2'
@@ -746,7 +742,6 @@ setup(name=NAME,
       ext_modules=[Extension("PIL._imaging", ["_imaging.c"])],
       include_package_data=True,
       packages=find_packages(),
-      scripts=glob.glob("Scripts/*.py"),
       test_suite='nose.collector',
       keywords=["Imaging", ],
       license='Standard PIL License',
