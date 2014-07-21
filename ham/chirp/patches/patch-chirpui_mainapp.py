$NetBSD: patch-chirpui_mainapp.py,v 1.1 2014/07/21 07:57:21 dbj Exp $
This software contains darwin specific tweaks which do not apply to pkgsrc

--- chirpui/mainapp.py.orig	2014-02-22 08:01:32.000000000 +0000
+++ chirpui/mainapp.py
@@ -1715,8 +1715,6 @@ If you think that it is valid, you can s
 
         if os.name != "nt":
             self._set_icon() # Windows gets the icon from the exe
-            if os.uname()[0] == "Darwin":
-                self._init_macos(mbar)
 
         vbox.pack_start(mbar, 0, 0, 0)
 
