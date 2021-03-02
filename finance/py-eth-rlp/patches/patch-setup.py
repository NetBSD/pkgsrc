$NetBSD: patch-setup.py,v 1.2 2021/03/02 04:03:31 mef Exp $

Fix for  python 3.6 only,
UnicodeDecodeError: 'ascii' codec can't decode byte 0xe2 in position 2014: ordinal not in range(128)

--- setup.py.orig	2020-10-15 02:15:17.000000000 +0900
+++ setup.py	2021-03-02 13:01:58.145270773 +0900
@@ -1,5 +1,6 @@
 #!/usr/bin/env python
 # -*- coding: utf-8 -*-
+import sys
 from setuptools import (
     setup,
     find_packages,
@@ -40,7 +41,7 @@ extras_require['dev'] = (
 )
 
 
-with open('./README.md') as readme:
+with open("README.md", **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})) as readme:
     long_description = readme.read()
 
 
