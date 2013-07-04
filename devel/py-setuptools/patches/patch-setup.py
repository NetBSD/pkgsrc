$NetBSD: patch-setup.py,v 1.1 2013/07/04 06:43:13 wiz Exp $

Do not install easy_install without python version suffix to allow
parallel installation of this package for multiple python versions.

--- setup.py.orig	2013-07-02 15:45:46.000000000 +0000
+++ setup.py
@@ -54,7 +54,7 @@ from setuptools.command.test import test
 
 scripts = []
 
-console_scripts = ["easy_install = setuptools.command.easy_install:main"]
+console_scripts = []
 
 # Gentoo distributions manage the python-version-specific scripts themselves,
 # so they define an environment variable to suppress the creation of the
