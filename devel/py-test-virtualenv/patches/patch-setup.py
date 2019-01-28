$NetBSD: patch-setup.py,v 1.1 2019/01/28 08:40:07 adam Exp $

Allow newer pytest.

--- setup.py.orig	2019-01-28 08:19:14.000000000 +0000
+++ setup.py
@@ -23,7 +23,7 @@ classifiers = [
 
 install_requires = ['pytest-fixture-config',
                     'pytest-shutil',
-                    'pytest<4.0.0',
+                    'pytest',
                     ]
 
 tests_require = [
