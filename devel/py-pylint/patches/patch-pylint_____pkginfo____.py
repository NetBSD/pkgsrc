$NetBSD: patch-pylint_____pkginfo____.py,v 1.1 2017/03/01 13:08:44 fhajny Exp $

Add PYVERSSUFFIX to scripts.

--- pylint/__pkginfo__.py.orig	2017-01-22 14:06:23.000000000 +0000
+++ pylint/__pkginfo__.py
@@ -19,7 +19,7 @@
 from __future__ import absolute_import
 
 from os.path import join
-
+import sys
 
 modname = distname = 'pylint'
 
@@ -76,7 +76,7 @@ long_desc = """\
  Pylint is shipped with "pylint-gui", "pyreverse" (UML diagram generator)
  and "symilar" (an independent similarities checker)."""
 
-scripts = [join('bin', filename)
+scripts = [join('bin', filename + sys.version[0:3])
            for filename in ('pylint', 'pylint-gui', "symilar", "epylint",
                             "pyreverse")]
 
