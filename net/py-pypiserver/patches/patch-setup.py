$NetBSD: patch-setup.py,v 1.4 2023/08/04 08:17:36 adam Exp $

Do not require setuptools-git for building.

--- setup.py.orig	2023-07-30 19:33:20.000000000 +0000
+++ setup.py
@@ -13,7 +13,7 @@ tests_require = [
     "webtest",
 ]
 
-setup_requires = ["setuptools", "setuptools-git >= 0.3", "wheel >= 0.25.0"]
+setup_requires = ["setuptools", "wheel >= 0.25.0"]
 install_requires = ["pip>=7"]
 
 
