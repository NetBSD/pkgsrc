$NetBSD: patch-setup.py,v 1.1 2023/09/15 14:34:48 leot Exp $

Avoid too strict dependency requirements.

At least urllib3 is problematic one, be greedy also for all the others
to avoid same patching in future.

--- setup.py.orig	2023-09-13 18:08:36.000000000 +0000
+++ setup.py
@@ -23,9 +23,9 @@ def find_version(*file_paths):
 
 
 requires = [
-    'jmespath>=0.7.1,<2.0.0',
-    'python-dateutil>=2.1,<3.0.0',
-    'urllib3>=1.25.4,<1.27',
+    'jmespath>=0.7.1',
+    'python-dateutil>=2.1',
+    'urllib3>=1.25.4',
 ]
 
 setup(
