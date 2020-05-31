$NetBSD: patch-setup.py,v 1.1 2020/05/31 20:49:33 joerg Exp $

--- setup.py.orig	2020-05-31 17:59:09.409031695 +0000
+++ setup.py
@@ -1,9 +1,10 @@
+import sys
 from setuptools import setup
 
 setup(
     name='pytest-testmon',
     description='find bugs 10x faster',
-    long_description=''.join(open('README.rst').readlines()),
+    long_description=''.join(open('README.rst', **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})).readlines()),
     version='0.9.19',
     license='MIT',
     platforms=['linux', 'osx', 'win32'],
