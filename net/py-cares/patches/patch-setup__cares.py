$NetBSD: patch-setup__cares.py,v 1.1 2018/10/22 15:50:28 jperkin Exp $

Fix build on SunOS.

--- setup_cares.py.orig	2017-04-25 06:44:35.000000000 +0000
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
             self.extensions[0].extra_link_args = ['/NODEFAULTLIB:libcmt']
