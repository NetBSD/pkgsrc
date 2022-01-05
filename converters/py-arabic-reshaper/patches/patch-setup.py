$NetBSD: patch-setup.py,v 1.3 2022/01/05 09:37:15 wiz Exp $

Fix building with Python 2.7.

--- setup.py.orig	2021-03-23 11:03:30.000000000 +0000
+++ setup.py
@@ -5,8 +5,8 @@ from setuptools import setup
 
 import os
 
-with open("README.md", "r", encoding="utf-8") as fh:
-    long_description = fh.read()
+with open("README.md", "rb") as fh:
+    long_description = fh.read().decode("utf-8")
 
 setup(
     name="arabic_reshaper",
