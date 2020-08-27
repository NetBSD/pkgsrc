$NetBSD: patch-setup.py,v 1.1 2020/08/27 12:32:49 joerg Exp $

--- setup.py.orig	2020-08-26 11:49:30.118420576 +0000
+++ setup.py
@@ -1,13 +1,13 @@
 from setuptools import setup
 
 import versioneer
-
+import sys
 
 def read(path):
     """
     Read the contents of a file.
     """
-    with open(path) as f:
+    with open(path, **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})) as f:
         return f.read()
 
 
