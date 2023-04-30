$NetBSD: patch-setup.py,v 1.1 2023/04/30 12:50:12 wiz Exp $

ruff is not packaged yet.

--- setup.py.orig	2023-04-23 21:44:59.000000000 +0000
+++ setup.py
@@ -5,7 +5,7 @@ import glob
 from setuptools import find_packages, setup
 
 install_requires = []
-tests_require = ["coverage", "pexpect", "wheel", "ruff", "mypy"]
+tests_require = ["coverage", "pexpect", "wheel", "mypy"]
 importlib_backport_requires = ["importlib-metadata >= 0.23, < 7"]
 
 setup(
