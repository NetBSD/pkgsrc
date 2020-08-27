$NetBSD: patch-setup.py,v 1.1 2020/08/27 12:27:00 joerg Exp $

--- setup.py.orig	2020-08-26 11:53:27.731267998 +0000
+++ setup.py
@@ -1,9 +1,10 @@
 from setuptools import setup, find_packages
+import sys
 
 install_requires = ["execnet>=1.1", "pytest>=4.4.0", "pytest-forked", "six"]
 
 
-with open("README.rst") as f:
+with open("README.rst", **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})) as f:
     long_description = f.read()
 
 setup(
