$NetBSD: patch-setup.py,v 1.7 2018/12/11 09:11:08 adam Exp $

Allow newer versions of dependencies.

--- setup.py.orig	2018-12-10 05:59:26.000000000 +0000
+++ setup.py
@@ -42,14 +42,14 @@ if sys.argv[-1] == 'publish':
 packages = ['requests']
 
 requires = [
-    'chardet>=3.0.2,<3.1.0',
-    'idna>=2.5,<2.9',
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
