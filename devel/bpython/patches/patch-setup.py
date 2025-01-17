$NetBSD: patch-setup.py,v 1.4 2025/01/17 19:21:09 adam Exp $

Use the same man directory across all platforms.

--- setup.py.orig	2025-01-17 09:32:25.000000000 +0000
+++ setup.py
@@ -344,10 +344,7 @@ if using_sphinx:
     cmdclass["build_sphinx"] = BuildDoc
     cmdclass["build_sphinx_man"] = BuildDoc
 
-    if platform.system() in ("FreeBSD", "OpenBSD"):
-        man_dir = "man"
-    else:
-        man_dir = "share/man"
+    man_dir = os.environ.get('PKGMANDIR', 'man')
 
     # manual pages
     man_pages = [
