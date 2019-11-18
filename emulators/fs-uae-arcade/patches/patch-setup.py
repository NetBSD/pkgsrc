$NetBSD: patch-setup.py,v 1.3 2019/11/18 20:01:03 adam Exp $

Fix installation on Darwin.

--- setup.py.orig	2015-10-27 20:54:58.000000000 +0000
+++ setup.py
@@ -178,10 +178,6 @@ if sys.argv[1] == "build_exe":
 if sys.platform == "win32" and False:
     setup_kwargs["windows"] = scripts
 
-if sys.platform == "darwin":
-    setup_kwargs["name"] = title
-    setup_kwargs["version"] = "3.0.2"
-else:
-    setup_kwargs["scripts"] = scripts
+setup_kwargs["scripts"] = scripts
 
 setup(**setup_kwargs)
