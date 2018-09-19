$NetBSD: patch-setup.py,v 1.1 2018/09/19 16:18:32 nia Exp $

Fix man page install location.

--- setup.py.orig	2018-05-19 09:02:48.000000000 +0000
+++ setup.py
@@ -113,7 +113,7 @@ def build_man(build_cmd):
 def install_man(install_cmd):
     data_files = install_cmd.distribution.data_files
     man_dir = os.path.join(build_dir, 'man')
-    target = 'share/man/man1'
+    target = 'man/man1'
 
     for man in MAN_FILES:
         man_file_gz = os.path.join(man_dir, man + '.gz')
