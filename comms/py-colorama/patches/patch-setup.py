$NetBSD: patch-setup.py,v 1.1 2021/01/09 00:43:43 mef Exp $

This patch is necessary only for python-3.6

Traceback (most recent call last):
  File "setup.py", line 36, in <module>
    long_description=read_file('README.rst'),
  File "setup.py", line 19, in read_file
    return fp.read()
  File "/usr/pkg/lib/python3.6/encodings/ascii.py", line 26, in decode
    return codecs.ascii_decode(input, self.errors)[0]
UnicodeDecodeError: 'ascii' codec can't decode byte 0xc2 in position 852: ordinal not in range(128)
*** Error code 1

--- setup.py.orig	2020-10-13 06:22:32.000000000 +0900
+++ setup.py	2021-01-09 09:24:27.258231596 +0900
@@ -5,6 +5,8 @@ from __future__ import with_statement
 
 import os
 import re
+import sys
+
 try:
     from setuptools import setup
 except ImportError:
@@ -15,7 +17,7 @@ NAME = 'colorama'
 
 
 def read_file(path):
-    with open(os.path.join(os.path.dirname(__file__), path)) as fp:
+    with open(os.path.join(os.path.dirname(__file__), path), **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})) as fp:
         return fp.read()
 
 def _get_version_match(content):
