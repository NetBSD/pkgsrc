$NetBSD: patch-setup.py,v 1.1 2017/08/06 19:55:11 adam Exp $

README does not contain ASCII characters.

--- setup.py.orig	2017-02-23 17:56:42.000000000 +0000
+++ setup.py
@@ -57,7 +57,10 @@ classifiers = [
 
 
 def get_long_description():
-    lines = open('README.rst').read().splitlines(False)
+    if sys.version_info.major >= 3:
+        lines = open('README.rst', encoding='utf-8').read().splitlines(False)
+    else:
+        lines = open('README.rst').read().splitlines(False)
     end = lines.index('Getting Started')
     return '\n' + '\n'.join(lines[:end]) + '\n'
 
