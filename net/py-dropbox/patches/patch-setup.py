$NetBSD: patch-setup.py,v 1.1 2021/04/22 09:33:02 nia Exp $

Unpin pytest-runner

--- setup.py.orig	2021-03-09 20:35:57.000000000 +0000
+++ setup.py
@@ -33,7 +33,7 @@ install_reqs = [
 setup_requires = [
     # Pin pytest-runner to 5.2.0, since 5.3.0 uses `find_namespaces` directive, not supported in
     # Python 2.7
-    'pytest-runner == 5.2.0',
+    'pytest-runner',
 ]
 
 # WARNING: This imposes limitations on test/requirements.txt such that the
