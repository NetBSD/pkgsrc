$NetBSD: patch-setup.py,v 1.1 2024/02/29 20:55:23 adam Exp $

Do not install tests.

--- setup.py.orig	2024-02-29 17:26:01.351370175 +0000
+++ setup.py
@@ -18,7 +18,7 @@ setuptools.setup(
     long_description=long_description,
     long_description_content_type="text/markdown",
     author_email='podalirius@protonmail.com',
-    packages=setuptools.find_packages(),
+    packages=setuptools.find_packages(exclude=['tests']),
     license='GPL2',
     classifiers=[
         "Programming Language :: Python :: 3",
