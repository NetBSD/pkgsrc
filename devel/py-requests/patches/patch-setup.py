$NetBSD: patch-setup.py,v 1.9 2020/02/21 06:42:59 adam Exp $

Allow newer test dependencies.

--- setup.py.orig	2020-02-18 22:55:51.000000000 +0000
+++ setup.py
@@ -49,7 +49,7 @@ requires = [
 
 ]
 test_requirements = [
-    'pytest-httpbin==0.0.7',
+    'pytest-httpbin>=0.0.7',
     'pytest-cov',
     'pytest-mock',
     'pytest-xdist',
