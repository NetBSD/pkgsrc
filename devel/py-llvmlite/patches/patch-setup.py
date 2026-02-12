$NetBSD: patch-setup.py,v 1.1 2026/02/12 07:33:48 wiz Exp $

dry_run flag was removed from setuptools.

--- setup.py.orig	2026-02-12 07:31:33.741515162 +0000
+++ setup.py
@@ -65,7 +65,7 @@ def build_library_files(dry_run):
     plt = sys.platform
     if 'linux' in plt or 'bsd' in plt or 'darwin' in plt or 'gnu' in plt:
         os.environ['CXXFLAGS'] = os.environ.get('CXXFLAGS', '') + ' -fPIC'
-    spawn(cmd, dry_run=dry_run)
+    spawn(cmd)
 
 
 class LlvmliteBuild(build):
