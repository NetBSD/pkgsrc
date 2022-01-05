$NetBSD: patch-setup.py,v 1.2 2022/01/05 09:12:55 wiz Exp $

Fix building with Python 2.7.

https://github.com/mpcabd/python-arabic-reshaper/issues/77

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
@@ -19,8 +19,7 @@ setup(
     license="MIT",
     packages=['arabic_reshaper'],
     install_requires=['configparser; python_version <"3"',
-                      'future',
-                      'setuptools'],
+                      'future',],
     extras_require={
         'with-fonttools': ['fonttools>=4.0; python_version >="3"',
                            'fonttools>=3.0<4.0; python_version <"3"']
