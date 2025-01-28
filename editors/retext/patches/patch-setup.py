$NetBSD: patch-setup.py,v 1.1 2025/01/28 02:31:38 gutteridge Exp $

Install the desktop file when packaging via a wheel.
https://github.com/retext-project/retext/issues/655

--- setup.py.orig	2024-12-29 11:06:52.000000000 +0000
+++ setup.py
@@ -70,8 +70,6 @@ class retext_install(install):
         if self.root and self.root.endswith('/wheel'):
             # Desktop files don't allow relative paths, and we don't know the
             # absolute path when building a wheel.
-            logging.info('removing the .desktop file from the wheel')
-            os.remove(desktop_file_path)
             return
         # Fix Exec and Icon fields in the desktop file
         icon_path = join(self.orig_install_lib, 'ReText', 'icons', 'retext.svg')
