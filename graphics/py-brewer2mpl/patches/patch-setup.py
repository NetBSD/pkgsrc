$NetBSD: patch-setup.py,v 1.1 2026/02/17 15:35:47 wiz Exp $

Fix build with setuptools 82.

--- setup.py.orig	2026-02-17 15:34:37.912569558 +0000
+++ setup.py
@@ -1,6 +1,3 @@
-from ez_setup import use_setuptools
-use_setuptools()
-
 from setuptools import setup
 
 with open('README.rst', 'r') as f:
