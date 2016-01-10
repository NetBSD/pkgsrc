$NetBSD: patch-setup.py,v 1.1 2016/01/10 13:42:02 kleink Exp $

Update to latest version of requests. Closes #89.
commit 7c9a1584aaa3a41008b182df45df8bf74cb26613

--- setup.py.orig	2015-12-03 03:52:12.000000000 +0000
+++ setup.py
@@ -14,7 +14,7 @@ if sys.version_info <= (2, 4):
 
 
 requirements = [
-    'requests<=2.6',
+    'requests<=2.9.1'
 ]
 
 setup(name='googlemaps',
