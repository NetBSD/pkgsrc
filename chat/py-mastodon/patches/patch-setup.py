$NetBSD: patch-setup.py,v 1.1 2024/08/10 14:37:30 wiz Exp $

https://github.com/halcy/Mastodon.py/issues/378

--- setup.py.orig	2024-08-10 12:02:10.316469270 +0000
+++ setup.py
@@ -2,7 +2,6 @@ from setuptools import setup
 
 test_deps = [
     'pytest', 
-    'pytest-runner', 
     'pytest-cov', 
     'vcrpy', 
     'pytest-vcr', 
