$NetBSD: patch-feed2exec_____init____.py,v 1.1 2020/01/29 16:48:48 schmonz Exp $

Avoid setuptools_scm since tarball has no .git.

--- feed2exec/__init__.py.orig	2019-02-26 22:03:32.000000000 +0000
+++ feed2exec/__init__.py
@@ -2,17 +2,8 @@
 
 from __future__ import print_function, absolute_import
 
-try:
-    from ._version import version
-except ImportError:  # pragma: nocover
-    try:
-        from setuptools_scm import get_version
-        version = get_version()
-    except (ImportError, LookupError):
-        version = '???'
-
 __description__ = 'The programmable feed reader'
-__version__ = version
+__version__ = '@PKGVERSION_NOREV@'
 __website__ = 'https://feed2exec.readthedocs.io/'
 __prog__ = 'feed2exec'
 __author__ = u'Antoine Beaupré'
