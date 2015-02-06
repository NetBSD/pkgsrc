$NetBSD: patch-main.c,v 1.1 2015/02/06 02:02:03 jmcneill Exp $

--- main.c.orig	2015-01-06 20:57:45.000000000 +0000
+++ main.c
@@ -257,7 +257,7 @@ int main(int argc, char *argv[])
 
   init_video();
 
-  sprintf(bios_filename, "%s" PATH_SEPARATOR "%s", main_path, "gba_bios.bin");
+  sprintf(bios_filename, "%s/.gpsp/gba_bios.bin", getenv("HOME"));
   ret = load_bios(bios_filename);
   if (ret != 0)
     ret = load_bios("gba_bios.bin");
@@ -278,7 +278,7 @@ int main(int argc, char *argv[])
 #ifdef PND_BUILD
     debug_screen_printl("in <SD card>/pandora/appdata/gpsp/ .              ");
 #else
-    debug_screen_printl("in the same directory as gpSP.                    ");
+    debug_screen_printl("in $HOME/.gpsp/ .                                 ");
 #endif
     debug_screen_printl("                                                  ");
     debug_screen_printl("Press any button to exit.                         ");
