$NetBSD: patch-setup.py,v 1.1 2026/06/26 06:35:07 adam Exp $

Fix build with Python 3.14.

--- setup.py.orig	2026-06-26 06:30:14.167210318 +0000
+++ setup.py
@@ -1,22 +1,4 @@
 from setuptools import setup
-import ast
-import os
-currentDir = os.path.dirname(os.path.abspath(__file__))
-#currentDir = Path(__file__).parent
+from filebytes.__init__ import VERSION
 
-def extractMetaInfo(src):
-    info = {}
-    a=ast.parse(src)
-    for e in a.body:
-        if isinstance(e, ast.Assign) and isinstance(e.value, ast.Str):
-            info[e.targets[0].id] = e.value.s
-    return info
-
-text = ''
-with open(currentDir  +os.path.sep+"filebytes"+ os.path.sep+"__init__.py") as f:
-    text = f.read()
-
-version = extractMetaInfo(text)["VERSION"]
-
-
-setup(version=version)
+setup(version=VERSION)
