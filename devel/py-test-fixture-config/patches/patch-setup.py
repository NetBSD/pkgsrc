$NetBSD: patch-setup.py,v 1.1 2019/01/28 08:41:37 adam Exp $

Allow newer pytest.

--- setup.py.orig	2019-01-15 08:36:48.000000000 +0000
+++ setup.py
@@ -21,7 +21,7 @@ classifiers = [
     'Programming Language :: Python :: 3.6',
 ]
 
-install_requires = ['pytest<4.0.0']
+install_requires = ['pytest']
 
 tests_require = ['six',
                  ]
