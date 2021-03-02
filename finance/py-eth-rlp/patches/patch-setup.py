$NetBSD: patch-setup.py,v 1.1 2021/03/02 03:53:35 mef Exp $

Fix for  python 3.6 only,
UnicodeDecodeError: 'ascii' codec can't decode byte 0xe2 in position 2014: ordinal not in range(128)

--- setup.py.orig	2020-10-15 02:15:17.000000000 +0900
+++ setup.py	2021-03-02 12:49:23.056851863 +0900
@@ -40,7 +40,7 @@ extras_require['dev'] = (
 )
 
 
-with open('./README.md') as readme:
+with open("README.md", **({'encoding': 'UTF-8'} if sys.version_info.major>=3 else {})) as readme:
     long_description = readme.read()
 
 
