$NetBSD: patch-setup.py,v 1.2 2020/01/16 08:20:02 adam Exp $

Do not require setuptools-git for building.

--- setup.py.orig	2019-09-17 18:56:54.000000000 +0000
+++ setup.py
@@ -20,7 +20,7 @@ tests_require = [
 if sys.version_info == (2, 7):
     tests_require.append("mock")
 
-setup_requires = ["setuptools", "setuptools-git >= 0.3"]
+setup_requires = ["setuptools"]
 if sys.version_info >= (3, 5):
     setup_requires.append("wheel >= 0.25.0")  # earlier wheels fail in 3.5
 else:
