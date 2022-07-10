$NetBSD: patch-setup.py,v 1.10 2022/07/10 20:09:56 wiz Exp $

Allow newer test dependencies.

--- setup.py.orig	2022-06-29 15:09:45.000000000 +0000
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
