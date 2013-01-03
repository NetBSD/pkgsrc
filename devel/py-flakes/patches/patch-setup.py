$NetBSD: patch-setup.py,v 1.1 2013/01/03 14:15:32 ryoon Exp $

--- setup.py.orig	2012-09-10 00:13:07.000000000 +0100
+++ setup.py	2012-09-10 00:17:04.000000000 +0100
@@ -2,6 +2,7 @@
 # Copyright 2005-2011 Divmod, Inc.  See LICENSE file for details
 
 from distutils.core import setup
+import sys
 
 setup(
     name="pyflakes",
@@ -14,7 +15,7 @@
     maintainer_email="divmod-dev@lists.launchpad.net",
     url="https://launchpad.net/pyflakes",
     packages=["pyflakes", "pyflakes.scripts", "pyflakes.test"],
-    scripts=["bin/pyflakes"],
+    scripts=["bin/pyflakes"+sys.version[0:3]],
     long_description="""Pyflakes is program to analyze Python programs and detect various errors. It
 works by parsing the source file, not importing it, so it is safe to use on
 modules with side effects. It's also much faster.""",
