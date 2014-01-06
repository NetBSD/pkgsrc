$NetBSD: patch-setup.py,v 1.2 2014/01/06 14:42:34 wiz Exp $

Do not install easy_install without python version suffix to allow
parallel installation of this package for multiple python versions.

--- setup.py.orig	2013-12-13 16:31:50.000000000 +0000
+++ setup.py
@@ -30,7 +30,7 @@ from setuptools.command.test import test
 scripts = []
 
 def _gen_console_scripts():
-    yield "easy_install = setuptools.command.easy_install:main"
+    yield ""
 
     # Gentoo distributions manage the python-version-specific scripts
     # themselves, so those platforms define an environment variable to
