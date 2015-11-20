$NetBSD: patch-ndiff_setup.py,v 1.1 2015/11/20 15:37:40 adam Exp $

Use PKGMANDIR.

--- ndiff/setup.py.orig	2015-09-20 04:16:36.000000000 +0000
+++ ndiff/setup.py
@@ -309,7 +309,7 @@ class my_uninstall(distutils.cmd.Command
 
 distutils.core.setup(name=u"ndiff", scripts=[u"scripts/ndiff"],
     py_modules=[u"ndiff"],
-    data_files=[(u"share/man/man1", [u"docs/ndiff.1"])],
+    data_files=[(u"@PKGMANDIR@/man1", [u"docs/ndiff.1"])],
     cmdclass={
         "install_egg_info": null_command,
         "install": checked_install,
