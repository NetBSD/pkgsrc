$NetBSD: patch-setup.py,v 1.1 2026/02/17 15:54:54 wiz Exp $

https://github.com/chapmanb/bcbb/issues/148

--- setup.py.orig	2026-02-17 15:52:37.029565857 +0000
+++ setup.py
@@ -1,8 +1,6 @@
 #!/usr/bin/env python
 """Python setup file for Blue Collar Bioinformatics scripts and modules.
 """
-from distribute_setup import use_setuptools
-use_setuptools()
 from setuptools import setup, find_packages
 
 __version__ = "Undefined"
