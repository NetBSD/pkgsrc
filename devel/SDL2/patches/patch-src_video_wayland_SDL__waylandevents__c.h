$NetBSD: patch-src_video_wayland_SDL__waylandevents__c.h,v 1.1 2020/04/05 16:22:42 nia Exp $

https://bugzilla.libsdl.org/show_bug.cgi?id=5074

--- src/video/wayland/SDL_waylandevents_c.h.orig	2020-03-11 01:36:18.000000000 +0000
+++ src/video/wayland/SDL_waylandevents_c.h
@@ -32,7 +32,7 @@ struct SDL_WaylandInput;
 
 extern void Wayland_PumpEvents(_THIS);
 
-extern void Wayland_display_add_input(SDL_VideoData *d, uint32_t id);
+extern void Wayland_display_add_input(SDL_VideoData *d, uint32_t id, uint32_t version);
 extern void Wayland_display_destroy_input(SDL_VideoData *d);
 
 extern SDL_WaylandDataDevice* Wayland_get_data_device(struct SDL_WaylandInput *input);
