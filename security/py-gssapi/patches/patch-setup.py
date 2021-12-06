$NetBSD: patch-setup.py,v 1.1 2021/12/06 14:45:22 wiz Exp $

Match this setting with py-setuptools.

--- setup.py.orig	2021-10-10 21:13:06.000000000 +0000
+++ setup.py
@@ -13,7 +13,7 @@ import shlex
 # the deprecation warning. Must be done before importing setuptools,
 # setuptools also must be imported before distutils.
 # https://github.com/pypa/setuptools/blob/main/docs/deprecated/distutils-legacy.rst
-os.environ['SETUPTOOLS_USE_DISTUTILS'] = 'local'
+#os.environ['SETUPTOOLS_USE_DISTUTILS'] = 'local'
 
 from setuptools import setup  # noqa: E402
 from setuptools import Distribution  # noqa: E402
