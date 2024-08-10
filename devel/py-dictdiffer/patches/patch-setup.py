$NetBSD: patch-setup.py,v 1.1 2024/08/10 06:42:57 wiz Exp $

Remove unused dependency.
https://github.com/inveniosoftware/dictdiffer/issues/167

--- setup.py.orig	2024-08-10 06:40:00.112856469 +0000
+++ setup.py
@@ -54,7 +54,6 @@ for key, reqs in extras_require.items():
     extras_require['all'].extend(reqs)
 
 setup_requires = [
-    'pytest-runner>=2.7',
     'setuptools_scm>=3.1.0',
 ]
 
