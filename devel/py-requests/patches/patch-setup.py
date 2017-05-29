$NetBSD: patch-setup.py,v 1.1 2017/05/29 10:43:42 adam Exp $

Allow newer pytest-httpbin (used only for testing).

--- setup.py.orig	2017-05-29 09:48:14.000000000 +0000
+++ setup.py
@@ -44,7 +44,7 @@ requires = [
     'certifi>=2017.4.17'
 
 ]
-test_requirements = ['pytest-httpbin==0.0.7', 'pytest-cov', 'pytest-mock', 'pytest-xdist', 'PySocks>=1.5.6, !=1.5.7', 'pytest>=2.8.0']
+test_requirements = ['pytest-httpbin>=0.0.7', 'pytest-cov', 'pytest-mock', 'pytest-xdist', 'PySocks>=1.5.6, !=1.5.7', 'pytest>=2.8.0']
 
 about = {}
 with open(os.path.join(here, 'requests', '__version__.py'), 'r', 'utf-8') as f:
