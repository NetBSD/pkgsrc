$NetBSD: patch-setup.py,v 1.2 2023/02/10 14:39:38 wiz Exp $

Fix invalid pattern.
Unpin pytest-runner

--- setup.py.orig	2022-06-15 23:27:44.000000000 +0000
+++ setup.py
@@ -27,13 +27,13 @@ version = eval(line.split('=', 1)[1].str
 install_reqs = [
     'requests >= 2.16.2',
     'six >= 1.12.0',
-    'stone >= 2.*',
+    'stone >= 2',
 ]
 
 setup_requires = [
     # Pin pytest-runner to 5.2.0, since 5.3.0 uses `find_namespaces` directive, not supported in
     # Python 2.7
-    'pytest-runner == 5.2.0',
+    'pytest-runner',
 ]
 
 # WARNING: This imposes limitations on test/requirements.txt such that the
