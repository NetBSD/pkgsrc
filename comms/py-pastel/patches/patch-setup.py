$NetBSD: patch-setup.py,v 1.1 2022/01/11 19:07:46 adam Exp $

Do not install tests.

--- setup.py.orig	2022-01-11 09:41:25.000000000 +0000
+++ setup.py
@@ -2,7 +2,7 @@
 from setuptools import setup
 
 packages = \
-['pastel', 'tests']
+['pastel']
 
 package_data = \
 {'': ['*']}
