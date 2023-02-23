$NetBSD: patch-setup.py,v 1.4 2023/02/23 15:59:24 schmonz Exp $

Tarball lacks .git, so pass down version from our Makefile.

--- setup.py.orig	2023-02-13 20:28:58.000000000 +0000
+++ setup.py
@@ -19,4 +19,4 @@
 from setuptools import setup
 
 if __name__ == '__main__':
-    setup()
+    setup(version='@VERSION@')
