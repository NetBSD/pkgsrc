$NetBSD: patch-setup.py,v 1.3 2016/07/21 12:54:49 wiz Exp $

Do not install easy_install without python version suffix to allow
parallel installation of this package for multiple python versions.

--- setup.py.orig	2016-07-14 05:17:28.000000000 +0000
+++ setup.py
@@ -28,7 +28,7 @@ scripts = []
 
 
 def _gen_console_scripts():
-    yield "easy_install = setuptools.command.easy_install:main"
+    yield ""
 
     # Gentoo distributions manage the python-version-specific scripts
     # themselves, so those platforms define an environment variable to
