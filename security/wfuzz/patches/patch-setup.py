$NetBSD: patch-setup.py,v 1.1 2023/02/10 14:37:20 wiz Exp $

Fix invalid pattern.

--- setup.py.orig	2020-11-06 11:04:27.000000000 +0000
+++ setup.py
@@ -31,7 +31,7 @@ dev_requires = [
 install_requires = [
     'pycurl',
     'pyparsing<2.4.2;python_version<="3.4"',
-    'pyparsing>=2.4*;python_version>="3.5"',
+    'pyparsing>=2.4;python_version>="3.5"',
     'six',
     'configparser;python_version<"3.5"',
     'chardet',
