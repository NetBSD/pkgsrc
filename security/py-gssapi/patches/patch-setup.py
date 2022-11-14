$NetBSD: patch-setup.py,v 1.2 2022/11/14 18:58:50 wiz Exp $

Match this setting with py-setuptools.

--- setup.py.orig	2022-10-25 18:55:45.000000000 +0000
+++ setup.py
@@ -11,7 +11,7 @@ import shlex
 # the deprecation warning. Must be done before importing setuptools,
 # setuptools also must be imported before distutils.
 # https://github.com/pypa/setuptools/blob/main/docs/deprecated/distutils-legacy.rst
-os.environ['SETUPTOOLS_USE_DISTUTILS'] = 'local'
+#os.environ['SETUPTOOLS_USE_DISTUTILS'] = 'local'
 
 from setuptools import setup  # noqa: E402
 from setuptools.extension import Extension  # noqa: E402
