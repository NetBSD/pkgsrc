$NetBSD: patch-setup.py,v 1.1 2025/01/14 16:58:59 adam Exp $

Do not install tests.

--- setup.py.orig	2025-01-14 16:56:45.972299015 +0000
+++ setup.py
@@ -77,7 +77,7 @@ setup(
         'Information and documentation can be found at '
         'https://github.com/gruns/icecream.'),
     platforms=['any'],
-    packages=find_packages(),
+    packages=find_packages(exclude=['tests']),
     include_package_data=True,
     classifiers=[
         'License :: OSI Approved :: MIT License',
