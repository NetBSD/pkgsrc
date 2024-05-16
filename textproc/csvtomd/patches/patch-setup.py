$NetBSD: patch-setup.py,v 1.3 2024/05/16 17:06:25 cheusov Exp $

https://github.com/mplewis/csvtomd/issues/10

--- setup.py.orig	2016-12-18 21:43:02.000000000 +0000
+++ setup.py
@@ -1,6 +1,6 @@
 from setuptools import setup
 
-with open('README.rst') as f:
+with open('README.md') as f:
     long_description = f.read()
 
 setup(
