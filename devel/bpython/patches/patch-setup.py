$NetBSD: patch-setup.py,v 1.3 2021/03/20 15:14:48 adam Exp $

Use the same man directory across all platforms.

--- setup.py.orig	2021-01-25 08:13:17.000000000 +0000
+++ setup.py
@@ -141,10 +141,7 @@ if using_sphinx:
     build.sub_commands.insert(0, ("build_sphinx_man", None))
     cmdclass["build_sphinx_man"] = BuildDoc
 
-    if platform.system() in ("FreeBSD", "OpenBSD"):
-        man_dir = "man"
-    else:
-        man_dir = "share/man"
+    man_dir = os.environ.get('PKGMANDIR', 'man')
 
     # manual pages
     man_pages = [
