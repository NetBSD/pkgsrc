$NetBSD: patch-setup.py,v 1.2 2016/07/28 09:54:59 wiz Exp $

https://github.com/mplewis/csvtomd/issues/10

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
