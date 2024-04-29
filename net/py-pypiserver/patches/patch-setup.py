$NetBSD: patch-setup.py,v 1.5 2024/04/29 10:53:03 adam Exp $

Do not require setuptools-git for building.

--- setup.py.orig	2024-04-24 23:59:20.000000000 +0000
+++ setup.py
@@ -16,7 +16,6 @@ tests_require = [
 
 setup_requires = [
     "setuptools",
-    "setuptools-git>=0.3",
     "wheel>=0.25.0",
 ]
 install_requires = [
