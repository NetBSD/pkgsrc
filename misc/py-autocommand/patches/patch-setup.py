$NetBSD: patch-setup.py,v 1.1 2023/11/27 06:55:57 adam Exp $

Fix build with setuptools 69.

--- setup.py.orig	2023-11-27 06:43:19.679895559 +0000
+++ setup.py
@@ -13,7 +13,6 @@ setup(
     ],
     package_dir={'': 'src'},
     platforms='any',
-    license='LGPLv3',
     author='Nathan West',
     url='https://github.com/Lucretiel/autocommand',
     description='A library to create a command-line program from a function',
