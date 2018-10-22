$NetBSD: patch-setup.py,v 1.6 2018/10/22 07:55:36 adam Exp $

Allow newer versions of dependencies.

--- setup.py.orig	2018-10-18 15:41:46.000000000 +0000
+++ setup.py
@@ -42,14 +42,14 @@ if sys.argv[-1] == 'publish':
 packages = ['requests']
 
 requires = [
-    'chardet>=3.0.2,<3.1.0',
-    'idna>=2.5,<2.8',
-    'urllib3>=1.21.1,<1.25',
+    'chardet>=3.0.2',
+    'idna>=2.5',
+    'urllib3>=1.21.1',
     'certifi>=2017.4.17'
 
 ]
 test_requirements = [
-    'pytest-httpbin==0.0.7',
+    'pytest-httpbin>=0.0.7',
     'pytest-cov',
     'pytest-mock',
     'pytest-xdist',
