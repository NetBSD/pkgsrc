$NetBSD: patch-setup.py,v 1.1 2019/05/07 09:42:33 adam Exp $

Conditionally require "typing" module.

--- setup.py.orig	2019-05-07 09:34:30.000000000 +0000
+++ setup.py
@@ -41,7 +41,7 @@ setup(name='curtsies',
       install_requires = [
           'blessings>=1.5',
           'wcwidth>=0.1.4',
-          'typing',
+          'typing;python_version<"3.5"',
       ],
       tests_require = [
           'mock',
