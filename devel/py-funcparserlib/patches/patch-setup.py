$NetBSD: patch-setup.py,v 1.1 2021/12/16 11:16:14 wiz Exp $

Fix build with latest setuptools.

--- setup.py.orig	2013-05-02 15:09:16.000000000 +0000
+++ setup.py
@@ -4,8 +4,6 @@ from setuptools import setup
 import sys
 
 extra = {}
-if sys.version_info >= (3,):
-    extra['use_2to3'] = True
 
 
 setup(
