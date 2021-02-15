$NetBSD: patch-setup.py,v 1.1 2021/02/15 14:59:25 mef Exp $

py36 gives following flag:
UnicodeDecodeError: 'ascii' codec can't decode byte 0xe2 in position 2861: ordinal not in range(128)

--- setup.py.orig	2021-01-22 04:52:10.000000000 +0900
+++ setup.py	2021-02-15 23:50:09.430652835 +0900
@@ -1,5 +1,6 @@
 #!/usr/bin/env python
 # -*- coding: utf-8 -*-
+import sys
 from setuptools import (
     setup,
     find_packages,
@@ -46,7 +47,7 @@ extras_require['dev'] = (
 )
 
 
-with open('./README.md') as readme:
+with open("./README.md", **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})) as readme:
     long_description = readme.read()
 
 
