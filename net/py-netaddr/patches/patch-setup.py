$NetBSD: patch-setup.py,v 1.1 2014/09/02 13:48:13 he Exp $

Prefer setup from setuptools, the older one may not
support install_requires or setup_requires

--- setup.py.orig	2014-07-06 05:19:54.000000000 +0000
+++ setup.py
@@ -8,7 +8,10 @@ A distutils Python setup file. For setup
 import os
 import sys
 
-from distutils.core import setup
+try:
+    from setuptools import setup
+except ImportError:
+    from distutils.core import setup
 
 if os.path.exists('MANIFEST'):
     os.remove('MANIFEST')
