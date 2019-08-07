$NetBSD: patch-run__uh.py,v 1.1 2019/08/07 12:07:35 nia Exp $

Add PREFIX to list of search paths.

--- run_uh.py.orig	2019-08-07 10:59:56.696840075 +0000
+++ run_uh.py
@@ -159,7 +159,7 @@ def get_content_dir_parent_path():
 	# Unknown Horizons.app/Contents/Resources/contents
 	options.append(os.getcwd())
 	# Try often-used paths on Linux.
-	for path in ('/usr/share/games', '/usr/share', '/usr/local/share/games', '/usr/local/share'):
+	for path in ('@PREFIX@/share', '/usr/share/games', '/usr/share', '/usr/local/share/games', '/usr/local/share'):
 		options.append(os.path.join(path, 'unknown-horizons'))
 
 	for path in options:
