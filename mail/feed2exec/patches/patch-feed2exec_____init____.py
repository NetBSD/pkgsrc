$NetBSD: patch-feed2exec_____init____.py,v 1.4 2023/02/23 15:59:24 schmonz Exp $

Tarball lacks .git, so pass down version from our Makefile.

--- feed2exec/__init__.py.orig	2023-02-13 20:28:58.000000000 +0000
+++ feed2exec/__init__.py
@@ -5,11 +5,7 @@ from __future__ import print_function, a
 try:
     from ._version import version
 except ImportError:  # pragma: nocover
-    try:
-        from setuptools_scm import get_version
-        version = get_version()
-    except (ImportError, LookupError):
-        version = '???'
+    version = '@VERSION@'
 
 __description__ = 'The programmable feed reader'
 __version__ = version
