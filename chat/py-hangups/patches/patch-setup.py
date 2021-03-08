$NetBSD: patch-setup.py,v 1.8 2021/03/08 21:28:27 leot Exp $

Avoid too strict version requirements.

--- setup.py.orig	2021-02-28 19:50:45.000000000 +0000
+++ setup.py
@@ -22,16 +22,16 @@ with open('README.rst') as f:
 # hangups from breaking when new versions of dependencies are released,
 # especially for end-users (non-developers) who use pip to install hangups.
 install_requires = [
-    'ConfigArgParse>=0.11.0,<2',
-    'aiohttp>=3.7,<4',
-    'async-timeout>=2,<4',
-    'appdirs>=1.4,<1.5',
-    'readlike>=0.1.2,<0.2',
-    'requests>=2.6.0,<3',  # uses semantic versioning (after 2.6)
-    'ReParser==1.4.3',
-    'protobuf>=3.1.0,<3.16',
-    'urwid>=1.3.1,<2.2',
-    'MechanicalSoup>=0.6.0,<0.13',
+    'ConfigArgParse>=0.11.0',
+    'aiohttp>=3.7',
+    'async-timeout>=2',
+    'appdirs>=1.4',
+    'readlike>=0.1.2',
+    'requests>=2.6.0',  # uses semantic versioning (after 2.6)
+    'ReParser>=1.4.3',
+    'protobuf>=3.1.0',
+    'urwid>=1.3.1',
+    'MechanicalSoup>=0.6.0',
 ]
 
 
