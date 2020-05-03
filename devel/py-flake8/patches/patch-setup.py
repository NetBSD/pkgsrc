$NetBSD: patch-setup.py,v 1.6 2020/05/03 09:59:52 adam Exp $

Relax requirements.

--- setup.py.orig	2020-05-03 09:56:44.000000000 +0000
+++ setup.py
@@ -19,10 +19,10 @@ requires = [
     # http://flake8.pycqa.org/en/latest/faq.html#why-does-flake8-use-ranges-for-its-dependencies
     # And in which releases we will update those ranges here:
     # http://flake8.pycqa.org/en/latest/internal/releases.html#releasing-flake8
-    "entrypoints >= 0.3.0, < 0.4.0",
-    "pyflakes >= 2.1.0, < 2.2.0",
-    "pycodestyle >= 2.5.0, < 2.6.0",
-    "mccabe >= 0.6.0, < 0.7.0",
+    "entrypoints >= 0.3.0",
+    "pyflakes >= 2.1.0",
+    "pycodestyle >= 2.5.0",
+    "mccabe >= 0.6.0",
 ]
 
 extras_require = {
