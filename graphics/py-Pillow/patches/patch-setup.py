$NetBSD: patch-setup.py,v 1.8 2016/10/04 19:30:24 adam Exp $

* Prevent to detect optional tkinter.
* Disable demo programs.

--- setup.py.orig	2016-10-04 14:54:44.000000000 +0000
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
 PILLOW_VERSION = '3.4.1'
@@ -746,7 +742,6 @@ setup(name=NAME,
       ext_modules=[Extension("PIL._imaging", ["_imaging.c"])],
       include_package_data=True,
       packages=find_packages(),
-      scripts=glob.glob("Scripts/*.py"),
       test_suite='nose.collector',
       keywords=["Imaging", ],
       license='Standard PIL License',
