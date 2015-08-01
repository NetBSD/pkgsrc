$NetBSD: patch-setup.py,v 1.1 2015/08/01 15:29:43 bsiegert Exp $

--- setup.py.orig	2014-04-23 17:13:49.000000000 +0900
+++ setup.py	2015-07-20 11:56:46.000000000 +0900
@@ -1,6 +1,7 @@
 #!/usr/bin/python
 
 import sys
+import setuptools
 from distutils.core import setup, Extension
 
 
