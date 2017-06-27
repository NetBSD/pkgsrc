$NetBSD: patch-setup.py,v 1.2 2017/06/27 23:33:08 wiedi Exp $

Use the same man directory across all platforms.

--- setup.py.orig	2016-10-10 19:21:11.000000000 +0000
+++ setup.py
@@ -185,10 +185,7 @@ if using_sphinx:
     build.sub_commands.insert(0, ('build_sphinx_man', None))
     cmdclass['build_sphinx_man'] = BuildDocMan
 
-    if platform.system() in ['FreeBSD', 'OpenBSD']:
-        man_dir = 'man'
-    else:
-        man_dir = 'share/man'
+    man_dir = os.environ.get('PKGMANDIR', 'man')
 
     # manual pages
     man_pages = [
