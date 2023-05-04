$NetBSD: patch-setup.py,v 1.1 2023/05/04 21:06:06 wiz Exp $

Relax requirement.

--- setup.py.orig	2022-01-25 21:31:58.000000000 +0000
+++ setup.py
@@ -22,9 +22,7 @@ with open('requirements.txt') as f:  # p
     install_reqs += f.read().splitlines()
 
 setup_requires = [
-    # Pin pytest-runner to 5.2.0, since 5.3.0 uses `find_namespaces` directive, not supported in
-    # Python 2.7
-    'pytest-runner == 5.2.0',
+    'pytest-runner',
 ]
 
 # WARNING: This imposes limitations on test/requirements.txt such that the
