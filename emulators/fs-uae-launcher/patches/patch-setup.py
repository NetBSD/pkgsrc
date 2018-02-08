$NetBSD: patch-setup.py,v 1.2 2018/02/08 20:57:27 adam Exp $

Fix installation on Darwin.

--- setup.py.orig	2017-01-08 19:48:56.000000000 +0000
+++ setup.py
@@ -174,10 +174,6 @@ if sys.argv[1] == "build_exe":
 if sys.platform == "win32" and False:
     setup_kwargs["windows"] = scripts
 
-if sys.platform == "darwin":
-    setup_kwargs["name"] = title
-    setup_kwargs["version"] = "2.8.3"
-else:
-    setup_kwargs["scripts"] = scripts
+setup_kwargs["scripts"] = scripts
 
 setup(**setup_kwargs)
