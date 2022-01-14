$NetBSD: patch-setup.py,v 1.1 2022/01/14 09:54:14 wiz Exp $

Remove incorrect check.

--- setup.py.orig	2015-08-27 15:11:16.000000000 +0000
+++ setup.py
@@ -121,10 +121,6 @@ class NameSpacePackager(object):
         self._split = None
         self.depth = self.full_package_name.count('.')
         self.command = None
-        if sys.argv[0] == 'setup.py' and sys.argv[1] == 'install' and \
-           '--single-version-externally-managed' not in sys.argv:
-            print('error: have to install with "pip install ."')
-            sys.exit(1)
         for x in sys.argv:
             if x[0] == '-' or x == 'setup.py':
                 continue
