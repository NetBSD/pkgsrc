$NetBSD: patch-setup.py,v 1.7 2025/09/14 10:29:34 adam Exp $

Fix installation on Darwin.

--- setup.py.orig	2025-09-06 22:20:15.000000000 +0000
+++ setup.py
@@ -178,10 +178,6 @@ if sys.argv[1] == "build_exe":
 if sys.platform == "win32" and False:
     setup_kwargs["windows"] = scripts
 
-if sys.platform == "darwin":
-    setup_kwargs["name"] = title
-    setup_kwargs["version"] = "3.2.20"
-else:
-    setup_kwargs["scripts"] = scripts
+setup_kwargs["scripts"] = scripts
 
 setup(**setup_kwargs)
