$NetBSD: patch-setup.py,v 1.1 2019/10/10 12:38:40 fox Exp $

Fixes paths of the man page and sample configuration file.

--- setup.py.orig	2019-08-26 16:48:11.736098643 +0000
+++ setup.py
@@ -34,7 +34,8 @@ def get_data_files():
     data_files = [
         ('share/doc/glances', ['AUTHORS', 'COPYING', 'NEWS.rst', 'README.rst',
                                'CONTRIBUTING.md', 'conf/glances.conf']),
-        ('share/man/man1', ['docs/man/glances.1'])
+        ('@PREFIX@/share/examples/glances', ['conf/glances.conf']),
+        ('@PREFIX@/@PKGMANDIR@/man1', ['docs/man/glances.1'])
     ]
 
     return data_files
