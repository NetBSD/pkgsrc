$NetBSD: patch-setup.py,v 1.1 2020/06/20 02:08:56 mef Exp $

Explicitly read file as UTF-8, thanks joerg@

--- setup.py.orig	2020-06-06 18:56:10.000000000 +0000
+++ setup.py
@@ -19,10 +19,11 @@
 # IN THE SOFTWARE.
 
 import os.path
+import sys
 from setuptools import setup, find_packages
 
 if os.path.exists('README.rst'):
-    with open('README.rst') as f:
+    with open('README.rst', **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})) as f:
         long_description = f.read()
 else:
     long_description = ""
