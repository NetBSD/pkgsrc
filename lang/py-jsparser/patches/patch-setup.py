$NetBSD: patch-setup.py,v 1.2 2017/07/11 19:24:31 adam Exp $

Use setuptools.

--- setup.py.orig	2017-07-09 11:31:42.000000000 +0000
+++ setup.py
@@ -1,4 +1,7 @@
-from distutils.core import setup
+try:
+    from setuptools import setup
+except ImportError:
+    from distutils.core import setup
 
 # python3 setup.py sdist upload -r pypi
 setup(
@@ -6,7 +9,6 @@ setup(
     version='2.5.2',
     packages=['pyjsparser'],
     url='https://github.com/PiotrDabkowski/pyjsparser',
-    install_requires = [],
     license='MIT',
     author='Piotr Dabkowski',
     author_email='piodrus@gmail.com',
