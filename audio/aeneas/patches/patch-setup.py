$NetBSD: patch-setup.py,v 1.1 2018/02/28 22:10:13 wiz Exp $

Always build C extension.

--- setup.py.orig	2017-03-16 12:48:53.000000000 +0000
+++ setup.py
@@ -297,7 +297,7 @@ elif FORCE_CEW:
     print("[INFO] ")
     EXTENSIONS.append(EXTENSION_CEW)
 else:
-    if IS_LINUX:
+    if 1:
         EXTENSIONS.append(EXTENSION_CEW)
     elif IS_OSX:
         print("[INFO] *********************************************************************************")
