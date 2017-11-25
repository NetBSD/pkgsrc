$NetBSD: patch-setup.py,v 1.1 2017/11/25 11:59:53 wiz Exp $

Install pkgconfig file into pkgsrc standard location.

--- setup.py.orig	2017-11-08 12:45:24.000000000 +0000
+++ setup.py
@@ -130,7 +130,7 @@ class install_pkgconfig(Command):
         if self.compiler_type == "msvc":
             return
 
-        pkgconfig_dir = os.path.join(self.install_data, "share", "pkgconfig")
+        pkgconfig_dir = os.path.join(self.install_data, "lib", "pkgconfig")
         self.mkpath(pkgconfig_dir)
 
         if sys.version_info[0] == 3:
