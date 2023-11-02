$NetBSD: patch-setup.py,v 1.2 2023/11/02 10:28:52 adam Exp $

Avoid too strict dependency requirements.

At least urllib3 is problematic one, be greedy also for all the others
to avoid same patching in future.

--- setup.py.orig	2023-11-01 18:12:52.000000000 +0000
+++ setup.py
@@ -23,10 +23,9 @@ def find_version(*file_paths):
 
 
 requires = [
-    'jmespath>=0.7.1,<2.0.0',
-    'python-dateutil>=2.1,<3.0.0',
-    'urllib3>=1.25.4,<1.27 ; python_version < "3.10"',
-    'urllib3>=1.25.4,<2.1 ; python_version >= "3.10"',
+    'jmespath>=0.7.1',
+    'python-dateutil>=2.1',
+    'urllib3>=1.25.4',
 ]
 
 extras_require = {
