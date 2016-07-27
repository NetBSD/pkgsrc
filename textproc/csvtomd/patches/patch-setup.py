$NetBSD: patch-setup.py,v 1.1 2016/07/27 23:15:45 cheusov Exp $

--- setup.py.orig	2014-07-14 00:13:47.000000000 +0000
+++ setup.py
@@ -1,7 +1,8 @@
 from setuptools import setup
 
-with open('README.rst') as f:
-    long_description = f.read()
+#with open('README.rst') as f:
+#    long_description = f.read()
+long_description=''
 
 setup(
     name='csvtomd',
