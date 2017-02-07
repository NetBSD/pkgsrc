$NetBSD: patch-setup.py,v 1.1 2017/02/07 23:48:57 joerg Exp $

--- setup.py.orig	2017-02-07 17:06:34.545212473 +0000
+++ setup.py
@@ -1,11 +1,13 @@
-from distutils.core import setup
+try:
+    from setuptools import setup
+except ImportError:
+    from distutils.core import setup
 
 setup(
     name='pyjsparser',
     version='2.4.5',
     packages=['pyjsparser'],
     url='https://github.com/PiotrDabkowski/pyjsparser',
-    install_requires = [],
     license='MIT',
     author='Piotr Dabkowski',
     author_email='piodrus@gmail.com',
