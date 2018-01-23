$NetBSD: patch-setup.py,v 1.1 2018/01/23 10:54:20 fhajny Exp $

Version the script file.

--- setup.py.orig	2018-01-22 17:28:26.000000000 +0000
+++ setup.py
@@ -10,6 +10,7 @@ from setuptools import setup, find_packa
 # To use a consistent encoding
 from codecs import open
 from os import path, listdir
+import sys
 
 version = 'unknown'
 with open(path.join(path.dirname(path.abspath(__file__)), 'VERSION'), encoding='utf-8') as version_file:
@@ -96,7 +97,7 @@ setup(
     # pip to create the appropriate form of executable for the target platform.
     entry_points={
         'console_scripts': [
-            'lexicon=lexicon.__main__:main',
+            'lexicon' + sys.version[0:3] + '=lexicon.__main__:main',
         ],
     },
     test_suite='tests'
