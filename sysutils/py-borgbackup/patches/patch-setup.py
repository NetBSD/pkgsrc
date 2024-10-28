$NetBSD: patch-setup.py,v 1.6 2024/10/28 09:59:34 he Exp $

Allow a newer version of py-msgpack.

--- setup.py.orig	2024-03-12 09:31:59.374517238 +0000
+++ setup.py
@@ -70,7 +70,7 @@ install_requires = [
     # Please note:
     # using any other msgpack version is not supported by borg development and
     # any feedback related to issues caused by this will be ignored.
-    'msgpack >=0.5.6, <=1.0.8, !=1.0.1',
+    'msgpack >=0.5.6, <=1.1.0, !=1.0.1',
     'packaging',
 ]
 
