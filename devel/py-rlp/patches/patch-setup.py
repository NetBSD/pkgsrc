$NetBSD: patch-setup.py,v 1.2 2022/07/12 07:28:27 adam Exp $

setuptools-markdown is deprecated for functionality included in setuptools.

--- setup.py.orig	2021-12-06 20:00:00.000000000 +0000
+++ setup.py
@@ -52,7 +52,7 @@ setup(
     url='https://github.com/ethereum/pyrlp',
     packages=find_packages(exclude=["tests", "tests.*"]),
     include_package_data=True,
-    setup_requires=['setuptools-markdown'],
+    setup_requires=[],
     install_requires=[
         "eth-utils>=2.0.0,<3",
     ],
