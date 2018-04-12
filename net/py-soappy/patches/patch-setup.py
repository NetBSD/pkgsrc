$NetBSD: patch-setup.py,v 1.1 2018/04/12 10:26:08 adam Exp $

Use proper encoding.

--- setup.py.orig	2018-04-12 09:14:03.000000000 +0000
+++ setup.py
@@ -5,11 +5,12 @@
 CVS=0
 
 from setuptools import setup, find_packages
+import io
 import os
 
 def read(*rnames):
-    return "\n"+ open(
-        os.path.join('.', *rnames)
+    return "\n"+ io.open(
+        os.path.join('.', *rnames), encoding='utf-8'
     ).read()
 url="https://github.com/kiorky/SOAPpy.git"
 long_description="SOAPpy provides tools for building SOAP clients and servers.  For more information see " + url\
