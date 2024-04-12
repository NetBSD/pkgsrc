$NetBSD: patch-setup.py,v 1.3 2024/04/12 11:10:21 adam Exp $

Avoid too strict dependency requirements.

At least urllib3 is problematic one, be greedy also for all the others
to avoid same patching in future.

--- setup.py.orig	2024-04-11 18:03:16.000000000 +0000
+++ setup.py
@@ -23,13 +23,12 @@ def find_version(*file_paths):
 
 
 requires = [
-    'jmespath>=0.7.1,<2.0.0',
-    'python-dateutil>=2.1,<3.0.0',
+    'jmespath>=0.7.1',
+    'python-dateutil>=2.1',
     # Prior to Python 3.10, Python doesn't require openssl 1.1.1
     # but urllib3 2.0+ does. This means all botocore users will be
     # broken by default on Amazon Linux 2 and AWS Lambda without this pin.
-    'urllib3>=1.25.4,<1.27 ; python_version < "3.10"',
-    'urllib3>=1.25.4,!=2.2.0,<3 ; python_version >= "3.10"',
+    'urllib3>=1.25.4,!=2.2.0,<3',
 ]
 
 extras_require = {
