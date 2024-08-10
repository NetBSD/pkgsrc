$NetBSD: patch-setup.py,v 1.3 2024/08/10 16:13:41 wiz Exp $

Remove unused depdendency.

--- setup.py.orig	2024-07-19 18:05:56.000000000 +0000
+++ setup.py
@@ -21,7 +21,6 @@ with open('requirements.txt') as f:  # p
     install_reqs += f.read().splitlines()
 
 setup_requires = [
-    'pytest-runner == 5.3.2',
 ]
 
 # WARNING: This imposes limitations on test/requirements.txt such that the
