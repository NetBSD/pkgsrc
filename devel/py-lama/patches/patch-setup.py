$NetBSD: patch-setup.py,v 1.1 2018/11/20 14:14:16 adam Exp $

Do not install tests.

--- setup.py.orig	2018-11-20 13:13:48.000000000 +0000
+++ setup.py
@@ -35,7 +35,7 @@ meta = dict(
     author_email='horneds@gmail.com',
     url=' https://github.com/klen/pylama',
 
-    packages=find_packages(exclude=['plugins']),
+    packages=find_packages(exclude=['tests']),
 
     entry_points={
         'console_scripts': [
