$NetBSD: patch-setup.py,v 1.4 2021/08/10 12:03:37 nia Exp $

Fix man page install location.

--- setup.py.orig	2021-04-24 11:27:40.000000000 +0000
+++ setup.py
@@ -109,7 +109,7 @@ def build_man(build_cmd):
 def install_man(install_cmd):
     data_files = install_cmd.distribution.data_files
     man_dir = build_dir / 'man'
-    target = 'share/man/man1'
+    target = os.path.join(os.environ['PKGMANDIR'], 'man1')
 
     for man in MAN_FILES:
         man_file_gz = str(man_dir / (man + '.gz'))
