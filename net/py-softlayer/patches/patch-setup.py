$NetBSD: patch-setup.py,v 1.1 2018/01/23 08:58:01 fhajny Exp $

Version Python scripts.

--- setup.py.orig	2018-01-15 20:57:28.000000000 +0000
+++ setup.py
@@ -1,6 +1,7 @@
 from __future__ import print_function
 import codecs
 import os
+import sys
 
 from setuptools import setup, find_packages
 
@@ -25,8 +26,8 @@ setup(
     url='http://github.com/softlayer/softlayer-python',
     entry_points={
         'console_scripts': [
-            'slcli = SoftLayer.CLI.core:main',
-            'sl = SoftLayer.CLI.deprecated:main',
+            'slcli' + sys.version[0:3] + ' = SoftLayer.CLI.core:main',
+            'sl' + sys.version[0:3] + ' = SoftLayer.CLI.deprecated:main',
         ],
     },
     install_requires=[
