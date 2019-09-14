$NetBSD: patch-setup.py,v 1.1 2019/09/14 11:05:09 nia Exp $

Use PKGMANDIR.

--- setup.py.orig	2016-01-31 14:36:20.000000000 +0000
+++ setup.py
@@ -56,7 +56,7 @@ versionfile.close()
 data_files = [
     ('share/sonata', ['README.rst', 'CHANGELOG', 'TODO', 'TRANSLATORS']),
     ('share/applications', ['sonata.desktop']),
-    ('share/man/man1', ['sonata.1']),
+    ('@PKGMANDIR@/man1', ['sonata.1']),
 ] + generate_translation_files()
 
 
