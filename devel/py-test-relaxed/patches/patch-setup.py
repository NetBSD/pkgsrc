$NetBSD: patch-setup.py,v 1.1 2017/11/15 09:23:17 adam Exp $

Open README.rst with proper encoding.

--- setup.py.orig	2017-10-19 03:09:37.000000000 +0000
+++ setup.py
@@ -1,4 +1,5 @@
 #!/usr/bin/env python
+import io
 
 from setuptools import setup, find_packages
 
@@ -19,7 +20,7 @@ setup(
     url="https://github.com/bitprophet/pytest-relaxed",
     author='Jeff Forcier',
     author_email='jeff@bitprophet.org',
-    long_description="\n" + open('README.rst').read(),
+    long_description="\n" + io.open('README.rst', encoding='utf-8').read(),
 
     packages=find_packages(),
     entry_points={
