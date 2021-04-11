$NetBSD: patch-setup.py,v 1.1 2021/04/11 16:59:36 wiz Exp $

setuptools-markdown is deprecated for functionality included in setuptools.

--- setup.py.orig	2020-11-23 15:09:47.000000000 +0000
+++ setup.py
@@ -52,7 +52,7 @@ setup(
     url='https://github.com/ethereum/pyrlp',
     packages=find_packages(exclude=["tests", "tests.*"]),
     include_package_data=True,
-    setup_requires=['setuptools-markdown'],
+    setup_requires=[],
     install_requires=[
         "eth-utils>=1.0.2,<2",
     ],
