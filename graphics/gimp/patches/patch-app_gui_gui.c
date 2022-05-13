$NetBSD: patch-app_gui_gui.c,v 1.1 2022/05/13 23:05:32 tnn Exp $

Fix build on macOS when not using gimp's GTK fork.
Upstream doesn't have this yet. Performance with pkgsrc gimp is still bad,
but at least it won't clutter up bulk builds.

--- app/gui/gui.c.orig	2021-12-19 20:48:33.000000000 +0000
+++ app/gui/gui.c
@@ -282,6 +282,9 @@ gui_init (Gimp     *gimp,
    * has the additional cost of an 8-bit (ARGB) to 10-bit conversion.
    * Let's disable this mode to regain the lost performance.
    */
+#ifndef GDK_OSX_BIG_SUR
+#define GDK_OSX_BIG_SUR GDK_OSX_MOJAVE 
+#endif
   if (gdk_quartz_osx_version () >= GDK_OSX_BIG_SUR)
     {
       NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
