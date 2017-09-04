$NetBSD: patch-setup.py,v 1.1 2017/09/04 13:58:24 leot Exp $

Avoid too strict version requirements.

--- setup.py.orig	2017-07-30 23:31:42.000000000 +0000
+++ setup.py
@@ -23,22 +23,22 @@ with open('README.rst') as f:
 # hangups from breaking when new versions of dependencies are released,
 # especially for end-users (non-developers) who use pip to install hangups.
 install_requires = [
-    'ConfigArgParse==0.11.0',
-    'aiohttp>=1.3,<3',
-    'appdirs>=1.4,<1.5',
-    'readlike==0.1.2',
-    'requests>=2.6.0,<3',  # uses semantic versioning (after 2.6)
-    'ReParser==1.4.3',
-    'protobuf>=3.1.0,<3.2.0',
-    'urwid==1.3.1',
-    'MechanicalSoup==0.6.0',
+    'ConfigArgParse>=0.11.0',
+    'aiohttp>=1.3',
+    'appdirs>=1.4',
+    'readlike>=0.1.2',
+    'requests>=2.6.0',  # uses semantic versioning (after 2.6)
+    'ReParser>=1.4.3',
+    'protobuf>=3.1.0',
+    'urwid>=1.3.1',
+    'MechanicalSoup>=0.6.0',
 ]
 
 
 if sys.version_info < (3, 4, 3):
     # For Python earlier than 3.4.3, use a backported asyncio that fixes an
     # issue with an exception being logged on exit.
-    install_requires.append('asyncio==3.4.3')
+    install_requires.append('asyncio>=3.4.3')
 
 
 setup(
