$NetBSD: patch-setup.py,v 1.8 2025/09/22 10:36:14 adam Exp $

Fix version number.
Fix installation on Darwin.

--- setup.py.orig	2025-09-18 15:34:18.000000000 +0000
+++ setup.py
@@ -20,7 +20,7 @@ title = "FS-UAE Launcher"
 name = "fs-uae-launcher"
 py_name = "fs_uae_launcher"
 tar_name = "fs-uae-launcher"
-version = "3.2.20"
+version = "3.2.35"
 author = "Frode Solheim"
 author_email = "frode@fs-uae.net"
 package_map = {
@@ -178,10 +178,6 @@ if sys.argv[1] == "build_exe":
 if sys.platform == "win32" and False:
     setup_kwargs["windows"] = scripts
 
-if sys.platform == "darwin":
-    setup_kwargs["name"] = title
-    setup_kwargs["version"] = "3.2.35"
-else:
-    setup_kwargs["scripts"] = scripts
+setup_kwargs["scripts"] = scripts
 
 setup(**setup_kwargs)
