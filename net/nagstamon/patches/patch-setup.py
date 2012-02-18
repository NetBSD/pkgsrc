$NetBSD: patch-setup.py,v 1.1 2012/02/18 17:05:27 gls Exp $

Install manpage in the proper location.

--- setup.py.orig	2011-10-24 13:03:20.000000000 +0000
+++ setup.py
@@ -50,6 +50,6 @@ setup(name = 'nagstamon',
     packages = ['Nagstamon', 'Nagstamon.Server'],
     package_dir = {'Nagstamon':'Nagstamon'},
     package_data = {'Nagstamon':['resources/*']},
-    data_files = [('%s/share/man/man1' % sys.prefix, ['Nagstamon/resources/nagstamon.1'])]
+    data_files = [('%s/@PKGMANDIR@/man1' % sys.prefix, ['Nagstamon/resources/nagstamon.1'])]
 )
 
