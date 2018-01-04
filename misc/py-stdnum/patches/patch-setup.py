$NetBSD: patch-setup.py,v 1.1 2018/01/04 20:44:10 adam Exp $

Read README file with UTF-8 enconding.

--- setup.py.orig	2018-01-04 20:35:54.000000000 +0000
+++ setup.py
@@ -21,6 +21,7 @@
 
 """python-stdnum installation script."""
 
+import io
 import os
 import sys
 from setuptools import setup, find_packages
@@ -34,7 +35,7 @@ if 'sdist' in sys.argv:
 
 base_dir = os.path.dirname(__file__)
 
-with open(os.path.join(base_dir, 'README'), 'r') as fp:
+with io.open(os.path.join(base_dir, 'README'), 'r', encoding='utf-8') as fp:
     long_description = fp.read()
 
 setup(name='python-stdnum',
