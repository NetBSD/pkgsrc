$NetBSD: patch-setup.py,v 1.2 2024/04/26 17:02:07 adam Exp $

Relax requirement.

--- setup.py.orig	2024-03-28 16:48:27.000000000 +0000
+++ setup.py
@@ -21,7 +21,7 @@ with open('requirements.txt') as f:  # p
     install_reqs += f.read().splitlines()
 
 setup_requires = [
-    'pytest-runner == 5.3.2',
+    'pytest-runner',
 ]
 
 # WARNING: This imposes limitations on test/requirements.txt such that the
