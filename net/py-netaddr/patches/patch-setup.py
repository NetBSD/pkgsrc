$NetBSD: patch-setup.py,v 1.2 2016/03/06 15:07:07 adam Exp $

Prefer setup from setuptools, the older one may not
support install_requires or setup_requires

--- setup.py.orig	2015-08-25 21:54:04.000000000 +0000
+++ setup.py
@@ -8,7 +8,10 @@ A distutils Python setup file. For setup
 import os
 import sys
 
-from distutils.core import setup, Command
+try:
+    from setuptools import setup, Command
+except ImportError:
+    from distutils.core import setup, Command
 
 if os.path.exists('MANIFEST'):
     os.remove('MANIFEST')
@@ -64,7 +67,6 @@ def main():
         version          = release.version,
         options = {
             'build_scripts': {
-                'executable': '/usr/bin/env python',
             },
         },
     )
