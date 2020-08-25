$NetBSD: patch-chirp_ui_mainapp.py,v 1.1 2020/08/25 13:50:36 gdt Exp $

This software contains darwin specific tweaks which do not apply to pkgsrc

--- chirp/ui/mainapp.py.orig	2020-07-03 15:43:54.520195801 +1000
+++ chirp/ui/mainapp.py	2020-07-03 15:49:25.663278078 +1000
@@ -2087,8 +2087,6 @@
 
         if os.name != "nt":
             self._set_icon()  # Windows gets the icon from the exe
-            if os.uname()[0] == "Darwin":
-                self._init_macos(mbar)
 
         vbox.pack_start(mbar, 0, 0, 0)
 
