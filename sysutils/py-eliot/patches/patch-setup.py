$NetBSD: patch-setup.py,v 1.2 2021/05/31 13:49:55 adam Exp $

Fix building for Python 3.6.

--- setup.py.orig	2020-12-15 19:13:04.000000000 +0000
+++ setup.py
@@ -7,7 +7,7 @@ def read(path):
     """
     Read the contents of a file.
     """
-    with open(path) as f:
+    with open(path, encoding='utf-8') as f:
         return f.read()
 
 
