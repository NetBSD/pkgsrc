$NetBSD: patch-setup.py,v 1.1 2017/07/16 00:16:43 schmonz Exp $

Use standard pkgsrc paths, and don't install RPM spec file.

--- setup.py.orig	2007-11-23 16:26:55.000000000 +0000
+++ setup.py
@@ -39,13 +39,12 @@ GETMAILDOCDIR = os.path.join(
     datadir or prefix,
     'share',
     'doc',
-    'getmail-%s' % __version__
+    'getmail'
 )
 
 GETMAILMANDIR = os.path.join(
     datadir or prefix,
-    'share',
-    'man',
+    os.environ["PKGMANDIR"],
     'man1'
 )
 
@@ -100,7 +99,6 @@ setup(
     data_files=[
         (GETMAILDOCDIR, [
             './README',
-            './getmail.spec',
             'docs/BUGS',
             'docs/COPYING',
             'docs/CHANGELOG',
