$NetBSD: patch-setup.py,v 1.2 2024/03/13 14:38:12 wiz Exp $

Always build C extension.

--- setup.py.orig	2017-03-16 12:48:53.000000000 +0000
+++ setup.py
@@ -234,7 +234,7 @@ EXTENSION_CEW = Extension(
         "aeneas/cew/cew_func.c"
     ],
     libraries=[
-        "espeak"
+        "espeak-ng"
     ]
 )
 EXTENSION_CFW = Extension(
@@ -297,7 +297,7 @@ elif FORCE_CEW:
     print("[INFO] ")
     EXTENSIONS.append(EXTENSION_CEW)
 else:
-    if IS_LINUX:
+    if 1:
         EXTENSIONS.append(EXTENSION_CEW)
     elif IS_OSX:
         print("[INFO] *********************************************************************************")
