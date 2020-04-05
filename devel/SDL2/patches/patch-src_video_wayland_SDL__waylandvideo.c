$NetBSD: patch-src_video_wayland_SDL__waylandvideo.c,v 1.3 2020/04/05 16:22:42 nia Exp $

https://bugzilla.libsdl.org/show_bug.cgi?id=5074

--- src/video/wayland/SDL_waylandvideo.c.orig	2020-03-11 01:36:18.000000000 +0000
+++ src/video/wayland/SDL_waylandvideo.c
@@ -364,7 +364,7 @@ display_handle_global(void *data, struct
     } else if (strcmp(interface, "wl_output") == 0) {
         Wayland_add_display(d, id);
     } else if (strcmp(interface, "wl_seat") == 0) {
-        Wayland_display_add_input(d, id);
+        Wayland_display_add_input(d, id, version);
     } else if (strcmp(interface, "xdg_wm_base") == 0) {
         d->shell.xdg = wl_registry_bind(d->registry, id, &xdg_wm_base_interface, 1);
         xdg_wm_base_add_listener(d->shell.xdg, &shell_listener_xdg, NULL);
