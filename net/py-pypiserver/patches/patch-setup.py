$NetBSD: patch-setup.py,v 1.3 2022/05/11 11:01:39 adam Exp $

Do not require setuptools-git for building.

--- setup.py.orig	2022-05-01 18:53:34.000000000 +0000
+++ setup.py
@@ -14,7 +14,7 @@ tests_require = [
     "webtest",
 ]
 
-setup_requires = ["setuptools", "setuptools-git >= 0.3", "wheel >= 0.25.0"]
+setup_requires = ["setuptools", "wheel >= 0.25.0"]
 
 
 def read_file(rel_path: str):
