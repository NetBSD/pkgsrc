$NetBSD: patch-setup.py,v 1.1 2016/07/09 21:13:02 wiz Exp $

Use setuptools for packaging to create nice eggs.

--- setup.py.orig	2010-07-28 06:19:12.000000000 +0900
+++ setup.py	2016-07-07 21:11:32.000000000 +0900
@@ -2,6 +2,7 @@
 # vim: set expandtab tabstop=4 shiftwidth=4:
 
 import os
+import setuptools
 from distutils.core import setup
 from distutils.extension import Extension
 
