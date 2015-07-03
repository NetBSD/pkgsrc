$NetBSD: patch-setup.py,v 1.2 2015/07/03 14:41:42 bouyer Exp $

Install manpage in the proper location.

--- setup.py.orig	2014-09-22 09:34:25.000000000 +0200
+++ setup.py	2015-05-21 12:42:03.000000000 +0200
@@ -50,6 +50,6 @@
     packages = ['Nagstamon', 'Nagstamon.Server', 'Nagstamon.thirdparty'],
     package_dir = {'Nagstamon':'Nagstamon'},
     package_data = {'Nagstamon':['resources/*']},
-    data_files = [('%s/share/man/man1' % sys.prefix, ['Nagstamon/resources/nagstamon.1'])]
+    data_files = [('%s/@PKGMANDIR@/man1' % sys.prefix, ['Nagstamon/resources/nagstamon.1'])]
 )
 
