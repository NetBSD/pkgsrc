$NetBSD: patch-setup.py,v 1.3 2024/08/10 07:14:15 wiz Exp $

Unpin stone.
Remove unused pytest-runner dependency.

--- setup.py.orig	2024-06-03 16:45:16.000000000 +0000
+++ setup.py
@@ -27,13 +27,10 @@ version = eval(line.split('=', 1)[1].str
 install_reqs = [
     'requests>=2.16.2',
     'six >= 1.12.0',
-    'stone>=2,<3.3.3',
+    'stone>=2',
 ]
 
 setup_requires = [
-    # Pin pytest-runner to 5.2.0, since 5.3.0 uses `find_namespaces` directive, not supported in
-    # Python 2.7
-    'pytest-runner==5.2.0',
 ]
 
 # WARNING: This imposes limitations on test/requirements.txt such that the
