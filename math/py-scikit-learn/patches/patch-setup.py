$NetBSD: patch-setup.py,v 1.1 2019/06/17 15:01:45 adam Exp $

Enable 'test' command.

--- setup.py.orig	2019-06-17 08:28:08.000000000 +0000
+++ setup.py
@@ -65,6 +65,7 @@ SETUPTOOLS_COMMANDS = {
     'bdist_wininst', 'install_egg_info', 'build_sphinx',
     'egg_info', 'easy_install', 'upload', 'bdist_wheel',
     '--single-version-externally-managed',
+    'test'
 }
 if SETUPTOOLS_COMMANDS.intersection(sys.argv):
     import setuptools
