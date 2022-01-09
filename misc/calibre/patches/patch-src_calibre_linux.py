$NetBSD: patch-src_calibre_linux.py,v 1.8 2022/01/09 15:43:51 rhialto Exp $

Disable installing files into $HOME that are not packaged anyway.

--- src/calibre/linux.py.orig	2020-02-21 03:27:12.000000000 +0000
+++ src/calibre/linux.py
@@ -729,8 +729,6 @@ class PostInstall:
         self.appdata_resources = []
         if islinux or isbsd:
             self.setup_completion()
-        if islinux or isbsd:
-            self.setup_desktop_integration()
         if not getattr(self.opts, 'staged_install', False):
             self.create_uninstaller()
 
