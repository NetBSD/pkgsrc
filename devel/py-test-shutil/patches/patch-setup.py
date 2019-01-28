$NetBSD: patch-setup.py,v 1.1 2019/01/28 08:41:12 adam Exp $

Allow newer pytest.

--- setup.py.orig	2019-01-15 08:36:49.000000000 +0000
+++ setup.py
@@ -24,7 +24,7 @@ classifiers = [
 install_requires = ['six',
                     'execnet',
                     'contextlib2',
-                    'pytest<4.0.0',
+                    'pytest',
                     'path.py',
                     'mock',
                     'termcolor'
