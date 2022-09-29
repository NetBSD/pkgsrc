$NetBSD: patch-setup.py,v 1.6 2022/09/29 09:26:15 adam Exp $

Fix installation on Darwin.

--- setup.py.orig	2022-01-26 18:26:58.000000000 +0000
+++ setup.py
@@ -178,10 +178,6 @@ if sys.argv[1] == "build_exe":
 if sys.platform == "win32" and False:
     setup_kwargs["windows"] = scripts
 
-if sys.platform == "darwin":
-    setup_kwargs["name"] = title
-    setup_kwargs["version"] = "3.1.68"
-else:
-    setup_kwargs["scripts"] = scripts
+setup_kwargs["scripts"] = scripts
 
 setup(**setup_kwargs)
