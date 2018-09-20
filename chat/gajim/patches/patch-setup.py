$NetBSD: patch-setup.py,v 1.2 2018/09/20 10:30:16 nia Exp $

Don't compress man pages.

Fix man page install location.

--- setup.py.orig	2018-05-19 09:02:48.000000000 +0000
+++ setup.py
@@ -112,11 +112,11 @@ def build_man(build_cmd):
 
 def install_man(install_cmd):
     data_files = install_cmd.distribution.data_files
-    man_dir = os.path.join(build_dir, 'man')
-    target = 'share/man/man1'
+    man_dir = 'data'
+    target = 'man/man1'
 
     for man in MAN_FILES:
-        man_file_gz = os.path.join(man_dir, man + '.gz')
+        man_file_gz = os.path.join(man_dir, man)
         data_files.append((target, [man_file_gz]))
 
 
@@ -164,7 +164,6 @@ class build(_build):
     def run(self):
         build_trans(self)
         if sys.platform != 'win32':
-            build_man(self)
             build_intl(self)
         _build.run(self)
 
