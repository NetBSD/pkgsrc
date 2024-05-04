$NetBSD: patch-setup.py,v 1.1 2024/05/04 23:52:06 jym Exp $

Fix man paths

--- setup.py.orig	2024-05-04 02:24:25.601004533 +0000
+++ setup.py
@@ -57,11 +57,11 @@ setup(
             'dknewkey = dkim.dknewkey:main'
         ],
     },
-    data_files = [(os.path.join('share', 'man', 'man1'),
-        ['man/arcsign.1']), (os.path.join('share', 'man', 'man1'),
-        ['man/arcverify.1']),(os.path.join('share', 'man', 'man1'),
-        ['man/dkimsign.1']), (os.path.join('share', 'man', 'man1'),
-        ['man/dkimverify.1']),(os.path.join('share', 'man', 'man1'),
+    data_files = [(os.path.join('@PKGMANDIR@', 'man1'),
+        ['man/arcsign.1']), (os.path.join('@PKGMANDIR@', 'man1'),
+        ['man/arcverify.1']),(os.path.join('@PKGMANDIR@', 'man1'),
+        ['man/dkimsign.1']), (os.path.join('@PKGMANDIR@', 'man1'),
+        ['man/dkimverify.1']),(os.path.join('@PKGMANDIR@', 'man1'),
         ['man/dknewkey.1']),],
     classifiers = [
       'Development Status :: 5 - Production/Stable',
