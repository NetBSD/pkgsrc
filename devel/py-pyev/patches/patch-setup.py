$NetBSD: patch-setup.py,v 1.1 2016/06/08 22:34:29 wiz Exp $

Remove broken version test.
pkgsrc makes sure we have new enough version.

--- setup.py.orig	2013-06-19 13:20:33.000000000 +0000
+++ setup.py
@@ -54,7 +54,6 @@ if "sdist" not in argv:
     python_version = python_version()
     major = python_version[0]
     check_version(python_version, min_python_versions[major], "Python{0}".format(major))
-    check_version(libev_version(), min_libev_version, "libev")
 
 
 PYEV_VERSION = "\"{0}\"".format(pyev_version)
