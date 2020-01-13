$NetBSD: patch-setup.py,v 1.1 2020/01/13 20:39:29 schmonz Exp $

Support PKGMANDIR.

--- setup.py.orig	2019-07-05 21:11:13.000000000 +0000
+++ setup.py
@@ -9,7 +9,7 @@ setup(
   scripts=['pius', 'pius-keyring-mgr', 'pius-party-worksheet', 'pius-report'],
   data_files=[
     (
-      'share/man/man1', [
+      '@PKGMANDIR@/man1', [
         'doc/pius-keyring-mgr.1',
         'doc/pius.1',
         'doc/pius-report.1',
