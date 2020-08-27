$NetBSD: patch-setup.py,v 1.3 2020/08/27 12:26:59 joerg Exp $

--- setup.py.orig	2020-08-26 11:44:55.860904637 +0000
+++ setup.py
@@ -2,7 +2,7 @@ from setuptools import setup
 import ast
 import os
 import io
-
+import sys
 
 def version():
     """Return version string."""
@@ -16,7 +16,7 @@ setup(
     name="curtsies",
     version=version(),
     description="Curses-like terminal wrapper, with colored strings!",
-    long_description=open("readme.md", encoding="utf-8").read(),
+    long_description=open("readme.md", **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})).read(),
     long_description_content_type="text/markdown",
     url="https://github.com/bpython/curtsies",
     author="Thomas Ballinger",
