$NetBSD: patch-setup__cares.py,v 1.2 2019/01/04 08:53:12 adam Exp $

Fix build on SunOS.

--- setup_cares.py.orig	2019-01-02 09:16:48.000000000 +0000
+++ setup_cares.py
@@ -85,9 +85,10 @@ class cares_build_ext(build_ext):
         elif sys.platform.startswith('openbsd'):
             self.compiler.add_include_dir(os.path.join(self.cares_dir, 'src/config_openbsd'))
         elif sys.platform.startswith('sunos'):
+            self.compiler.add_include_dir(os.path.join(self.cares_dir, 'src/config_sunos'))
             self.compiler.add_library('socket')
             self.compiler.add_library('nsl')
-            self.compiler.add_library('lkstat')
+            self.compiler.add_library('kstat')
         elif sys.platform == 'win32':
             self.compiler.add_include_dir(os.path.join(self.cares_dir, 'src/config_win32'))
             if "mingw" not in self.compiler.compiler_type:
