$NetBSD: patch-setup.py,v 1.1 2016/10/27 12:30:23 jperkin Exp $

Use pkgsrc layout.

--- setup.py.orig	2015-08-12 19:53:43.000000000 +0000
+++ setup.py
@@ -13,11 +13,9 @@ setup(name='pypolicyd-spf',
       py_modules=['policydspfsupp', 'policydspfuser'],
       keywords = ['Postfix','spf','email'],
       scripts = ['policyd-spf'],
-      data_files=[(os.path.join('share', 'man', 'man1'),
-          ['policyd-spf.1']), (os.path.join('share', 'man', 'man5'),
-          ['policyd-spf.conf.5']), (os.path.join('/etc', 'python-policyd-spf'),
-          ['policyd-spf.conf']), (os.path.join('share', 'man', 'man5'),
-          ['policyd-spf.peruser.5'])],
+      data_files=[(os.path.join('@PKGMANDIR@', 'man1'), ['policyd-spf.1']),
+                  (os.path.join('@PKGMANDIR@', 'man5'), ['policyd-spf.conf.5']),
+                  (os.path.join('@PKGMANDIR@', 'man5'), ['policyd-spf.peruser.5'])],
       classifiers = [
         'Development Status :: 5 - Production/Stable',
         'Environment :: No Input/Output (Daemon)',
