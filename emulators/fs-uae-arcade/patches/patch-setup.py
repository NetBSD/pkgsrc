$NetBSD: patch-setup.py,v 1.1 2018/02/08 20:58:50 adam Exp $

Fix installation on Darwin.

--- setup.py.orig	2015-10-27 20:54:58.000000000 +0000
+++ setup.py
@@ -172,10 +172,6 @@ if sys.argv[1] == "build_exe":
 if sys.platform == "win32" and False:
     setup_kwargs["windows"] = scripts
 
-if sys.platform == "darwin":
-    setup_kwargs["name"] = title
-    setup_kwargs["version"] = "2.8.3"
-else:
-    setup_kwargs["scripts"] = scripts
+setup_kwargs["scripts"] = scripts
 
 setup(**setup_kwargs)
