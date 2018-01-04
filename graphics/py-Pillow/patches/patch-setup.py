$NetBSD: patch-setup.py,v 1.14 2018/01/04 20:59:50 adam Exp $

Prevent to detect optional tkinter.

--- setup.py.orig	2018-01-04 20:47:56.000000000 +0000
+++ setup.py
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
