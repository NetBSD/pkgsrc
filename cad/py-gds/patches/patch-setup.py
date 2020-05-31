$NetBSD: patch-setup.py,v 1.1 2020/05/31 20:49:33 joerg Exp $

--- setup.py.orig	2020-05-31 17:53:41.141364832 +0000
+++ setup.py
@@ -12,7 +12,7 @@ import platform
 from setuptools import setup, Extension
 from distutils.version import LooseVersion
 
-with open("README.md") as fin:
+with open("README.md", **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})) as fin:
     long_description = fin.read()
 
 with open("gdspy/__init__.py") as fin:
