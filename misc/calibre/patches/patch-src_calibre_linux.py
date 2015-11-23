$NetBSD: patch-src_calibre_linux.py,v 1.7 2015/11/23 11:03:40 wiz Exp $

Disable installing files into $HOME that are not packaged anyway.

--- src/calibre/linux.py.orig	2015-11-15 04:15:13.000000000 +0000
+++ src/calibre/linux.py
@@ -691,8 +691,6 @@ class PostInstall:
         self.appdata_resources = []
         if islinux or isbsd:
             self.setup_completion()
-        if islinux or isbsd:
-            self.setup_desktop_integration()
         self.create_uninstaller()
 
         from calibre.utils.config import config_dir
