$NetBSD: patch-setup.py,v 1.3 2018/04/21 12:37:46 wiz Exp $

Use latest msgpack version

--- setup.py.orig	2018-03-30 07:08:16.000000000 +0000
+++ setup.py
@@ -39,7 +39,7 @@ install_requires = [
     # msgpack pure python data corruption was fixed in 0.4.6.
     # msgpack 0.5.0 was a bit of a troublemaker.
     # also, msgpack dropped py34 support at 0.5.0.
-    'msgpack-python>=0.4.6,<0.5.0',
+    'msgpack',
 ]
 
 # note for package maintainers: if you package borgbackup for distribution,
