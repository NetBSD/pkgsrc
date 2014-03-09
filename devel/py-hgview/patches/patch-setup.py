$NetBSD: patch-setup.py,v 1.1 2014/03/09 10:27:04 bsiegert Exp $

NetBSD bmake is incompatible with the Makefile. pkgsrc provides GNU make as
gmake so use it.
--- setup.py.orig	2014-02-15 11:11:16.000000000 +0000
+++ setup.py
@@ -163,10 +163,7 @@ class build_doc(_build):
     def run(self):
         # be sure to compile man page
         self.mkpath(self.build_dir)
-        if sys.platform.startswith('freebsd'):
-            make_cmd = 'gmake'
-        else:
-            make_cmd = 'make'
+        make_cmd = 'gmake'
         try:
             check_call([make_cmd, '-C', self.build_dir,
                         '-f', '../../doc/Makefile', 'VPATH=../../doc'])
