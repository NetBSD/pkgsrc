$NetBSD: patch-eel_eel-background.c,v 1.1 2016/05/22 13:01:45 youri Exp $

Fix build on Darwin.

--- eel/eel-background.c.orig	2015-07-16 07:11:15.000000000 +0000
+++ eel/eel-background.c
@@ -450,6 +450,8 @@ set_root_surface (EelBackground *self,
         mate_bg_set_surface_as_root (screen, self->details->bg_surface);
 }
 
+GSettings *mate_background_preferences;
+
 static void
 init_fade (EelBackground *self)
 {
