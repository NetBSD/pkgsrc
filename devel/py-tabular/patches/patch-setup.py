$NetBSD: patch-setup.py,v 1.1 2013/06/02 01:47:54 dholland Exp $

This package tries to insist on using py-distribute instead of
py-setuptools. But, those packages conflict and things this package
depends on require having py-setuptools installed. Meanwhile, our
infrastructure appears to only support using py-setuptools with Python
3.x, which this package doesn't support at all anyway.

So disable the prohibition against falling back to py-setuptools.

As far as I can tell it works fine this way.

--- setup.py.orig	2013-02-23 21:20:11.000000000 +0000
+++ setup.py
@@ -24,7 +24,7 @@ dependency_links = None
 # ----- control flags -----
 
 # fallback to setuptools if distribute isn't found
-setup_tools_fallback = False
+setup_tools_fallback = True
 
 # don't include subdir named 'tests' in package_data
 skip_tests = True
