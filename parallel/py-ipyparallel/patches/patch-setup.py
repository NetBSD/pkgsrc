$NetBSD: patch-setup.py,v 1.1 2022/02/04 13:09:41 adam Exp $

Do not install configuration files into /etc.

--- setup.py.orig	2022-02-04 13:05:19.000000000 +0000
+++ setup.py
@@ -34,7 +34,7 @@ package_data_spec = {'ipyparallel.nbexte
 data_files_spec = [
     # all extension-enabling config files
     (
-        'etc/jupyter',
+        'share/examples/jupyter',
         'etc/jupyter',
         '**',
     ),
