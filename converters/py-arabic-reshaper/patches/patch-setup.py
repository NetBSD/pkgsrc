$NetBSD: patch-setup.py,v 1.1 2021/04/28 09:52:18 adam Exp $

Fix building with Python 2.7.

--- setup.py.orig	2021-04-28 09:49:06.000000000 +0000
+++ setup.py
@@ -5,8 +5,8 @@ from setuptools import setup
 
 import os
 
-with open("README.md", "r", encoding="utf-8") as fh:
-    long_description = fh.read()
+with open("README.md", "rb") as fh:
+    long_description = fh.read().decode("utf-8")
 
 setup(
     name="arabic_reshaper",
