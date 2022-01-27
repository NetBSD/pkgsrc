$NetBSD: patch-setup.py,v 1.1 2022/01/27 10:29:54 wiz Exp $

Relax restrictions.

--- setup.py.orig	2021-09-21 20:34:58.000000000 +0000
+++ setup.py
@@ -29,7 +29,7 @@ for the machine in a thread- and process
 """
 
 requires = [
-    'rsa==4.7.2',
+    'rsa',
     'boto>=2.29.1',
     'google-reauth>=0.1.0',
     'httplib2>=0.18',
