$NetBSD: patch-setup.py,v 1.5 2020/05/23 09:12:58 adam Exp $

Fix installation on Darwin.

--- setup.py.orig	2017-01-08 19:48:56.000000000 +0000
+++ setup.py
@@ -180,10 +180,6 @@ if sys.argv[1] == "build_exe":
 if sys.platform == "win32" and False:
     setup_kwargs["windows"] = scripts
 
-if sys.platform == "darwin":
-    setup_kwargs["name"] = title
-    setup_kwargs["version"] = "3.0.5"
-else:
-    setup_kwargs["scripts"] = scripts
+setup_kwargs["scripts"] = scripts
 
 setup(**setup_kwargs)
