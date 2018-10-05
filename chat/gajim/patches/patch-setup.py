$NetBSD: patch-setup.py,v 1.3 2018/10/05 12:56:36 nia Exp $

Fix man page install location.

--- setup.py.orig	2018-10-05 12:43:13.496034076 +0000
+++ setup.py
@@ -113,7 +113,7 @@ def build_man(build_cmd):
 def install_man(install_cmd):
     data_files = install_cmd.distribution.data_files
     man_dir = os.path.join(build_dir, 'man')
-    target = 'share/man/man1'
+    target = os.path.join(os.environ['PKGMANDIR'], 'man1')
 
     for man in MAN_FILES:
         man_file_gz = os.path.join(man_dir, man + '.gz')
