$NetBSD: patch-setup.py,v 1.1 2023/11/20 06:36:47 wiz Exp $

https://github.com/kivy/kivy/pull/8326/files

--- setup.py.orig	2023-11-20 06:26:46.811168742 +0000
+++ setup.py
@@ -597,10 +597,6 @@ class CythonExtension(Extension):
             'language_level': 3,
             'unraisable_tracebacks': True,
         }
-        # XXX with pip, setuptools is imported before distutils, and change
-        # our pyx to c, then, cythonize doesn't happen. So force again our
-        # sources
-        self.sources = args[1]
 
 
 def merge(d1, *args):
