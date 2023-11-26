$NetBSD: patch-setup.py,v 1.1 2023/11/26 14:34:00 adam Exp $

Remove ez_setup.

--- setup.py.orig	2023-11-26 14:31:01.416557785 +0000
+++ setup.py
@@ -1,6 +1,3 @@
-from ez_setup import use_setuptools
-use_setuptools()
-
 from setuptools import setup
 
 setup(
