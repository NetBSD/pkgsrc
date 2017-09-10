$NetBSD: patch-setup.py,v 1.1 2017/09/10 12:34:12 adam Exp $

Allow newer pyflakes.

--- setup.py.orig	2017-08-04 06:17:09.000000000 +0000
+++ setup.py
@@ -17,7 +17,7 @@ tests_require = ['mock >= 2.0.0', 'pytes
 # NOTE(sigmavirus24): When updating these requirements, update them in
 # setup.cfg as well.
 requires = [
-    "pyflakes >= 1.5.0, < 1.6.0",
+    "pyflakes >= 1.5.0",
     "pycodestyle >= 2.0.0, < 2.4.0",
     "mccabe >= 0.6.0, < 0.7.0",
     "setuptools >= 30",
