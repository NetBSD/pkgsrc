$NetBSD: patch-setup.py,v 1.4 2017/08/16 07:17:58 adam Exp $

Allow newer versions of dependencies.

--- setup.py.orig	2017-08-15 13:19:39.000000000 +0000
+++ setup.py
@@ -42,13 +42,13 @@ if sys.argv[-1] == 'publish':
 packages = ['requests']
 
 requires = [
-    'chardet>=3.0.2,<3.1.0',
-    'idna>=2.5,<2.7',
-    'urllib3>=1.21.1,<1.23',
+    'chardet>=3.0.2',
+    'idna>=2.5',
+    'urllib3>=1.21.1',
     'certifi>=2017.4.17'
 
 ]
-test_requirements = ['pytest-httpbin==0.0.7', 'pytest-cov', 'pytest-mock', 'pytest-xdist', 'PySocks>=1.5.6, !=1.5.7', 'pytest>=2.8.0']
+test_requirements = ['pytest-httpbin>=0.0.7', 'pytest-cov', 'pytest-mock', 'pytest-xdist', 'PySocks>=1.5.6, !=1.5.7', 'pytest>=2.8.0']
 
 about = {}
 with open(os.path.join(here, 'requests', '__version__.py'), 'r', 'utf-8') as f:
