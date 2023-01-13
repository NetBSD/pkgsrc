$NetBSD: patch-setup.py,v 1.12 2023/01/13 09:01:02 adam Exp $

Allow newer test dependencies.

--- setup.py.orig	2023-01-12 16:16:59.000000000 +0000
+++ setup.py
@@ -65,7 +65,7 @@ requires = [
     "certifi>=2017.4.17",
 ]
 test_requirements = [
-    "pytest-httpbin==0.0.7",
+    "pytest-httpbin>=0.0.7",
     "pytest-cov",
     "pytest-mock",
     "pytest-xdist",
