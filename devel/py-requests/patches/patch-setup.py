$NetBSD: patch-setup.py,v 1.11 2022/11/25 10:46:37 adam Exp $

Allow newer test dependencies.

--- setup.py.orig	2022-06-29 15:09:45.000000000 +0000
+++ setup.py
@@ -59,13 +59,13 @@ if sys.argv[-1] == "publish":
     sys.exit()
 
 requires = [
-    "charset_normalizer>=2,<3",
+    "charset_normalizer>=2",
     "idna>=2.5,<4",
     "urllib3>=1.21.1,<1.27",
     "certifi>=2017.4.17",
 ]
 test_requirements = [
-    "pytest-httpbin==0.0.7",
+    "pytest-httpbin>=0.0.7",
     "pytest-cov",
     "pytest-mock",
     "pytest-xdist",
