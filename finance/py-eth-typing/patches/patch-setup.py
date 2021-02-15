$NetBSD: patch-setup.py,v 1.1 2021/02/15 15:14:56 mef Exp $

UnicodeDecodeError: 'ascii' codec can't decode byte 0xe2 in position 2071: ordinal not in range(128)

--- setup.py.orig	2020-09-03 09:31:05.000000000 +0900
+++ setup.py	2021-02-16 00:03:32.721946377 +0900
@@ -1,5 +1,6 @@
 #!/usr/bin/env python
 # -*- coding: utf-8 -*-
+import sys
 from setuptools import (
     setup,
     find_packages,
@@ -38,7 +39,7 @@ extras_require['dev'] = (
 )
 
 
-with open('./README.md') as readme:
+with open("./README.md", **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})) as readme:
     long_description = readme.read()
 
 
