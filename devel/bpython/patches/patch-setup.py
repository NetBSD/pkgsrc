$NetBSD: patch-setup.py,v 1.1 2017/05/25 06:38:44 adam Exp $

Use the same man directory across all platforms.

--- setup.py.orig	2017-05-25 06:32:08.000000000 +0000
+++ setup.py
@@ -185,10 +185,7 @@ if using_sphinx:
     build.sub_commands.insert(0, ('build_sphinx_man', None))
     cmdclass['build_sphinx_man'] = BuildDocMan
 
-    if platform.system() in ['FreeBSD', 'OpenBSD']:
-        man_dir = 'man'
-    else:
-        man_dir = 'share/man'
+    man_dir = 'man'
 
     # manual pages
     man_pages = [
