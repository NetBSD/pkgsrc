$NetBSD: patch-setup.py,v 1.1 2018/02/22 09:49:46 adam Exp $

Use proper encoding.

--- setup.py.orig	2018-02-22 09:45:05.000000000 +0000
+++ setup.py
@@ -1,3 +1,4 @@
+import io
 from setuptools import setup
 
 
@@ -20,7 +21,7 @@ setup(
     author='Bruno Oliveira',
     author_email='nicoddemus@gmail.com',
     description='Thin-wrapper around the mock package for easier use with py.test',
-    long_description=open('README.rst').read(),
+    long_description=io.open('README.rst', encoding='utf-8').read(),
     keywords="pytest mock",
     classifiers=[
         'Development Status :: 5 - Production/Stable',
