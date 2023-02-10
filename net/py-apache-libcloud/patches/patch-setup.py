$NetBSD: patch-setup.py,v 1.1 2023/02/10 14:41:16 wiz Exp $

Fix invalid pattern.

--- setup.py.orig	2020-04-04 19:15:42.000000000 +0000
+++ setup.py
@@ -271,7 +271,7 @@ setup(
     author='Apache Software Foundation',
     author_email='dev@libcloud.apache.org',
     install_requires=INSTALL_REQUIREMENTS,
-    python_requires=">=3.5.*, <4",
+    python_requires=">=3.5, <4",
     packages=get_packages('libcloud'),
     package_dir={
         'libcloud': 'libcloud',
