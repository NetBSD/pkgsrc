$NetBSD: patch-src_video_wayland_SDL__waylandvideo.c,v 1.1 2020/02/24 11:55:36 nia Exp $

https://bugzilla.libsdl.org/show_bug.cgi?id=4924

--- src/video/wayland/SDL_waylandvideo.c.orig	2019-07-25 04:32:36.000000000 +0000
+++ src/video/wayland/SDL_waylandvideo.c
@@ -381,7 +381,7 @@ display_handle_global(void *data, struct
     } else if (strcmp(interface, "zwp_pointer_constraints_v1") == 0) {
         Wayland_display_add_pointer_constraints(d, id);
     } else if (strcmp(interface, "wl_data_device_manager") == 0) {
-        d->data_device_manager = wl_registry_bind(d->registry, id, &wl_data_device_manager_interface, 3);
+        d->data_device_manager = wl_registry_bind(d->registry, id, &wl_data_device_manager_interface, SDL_min(3, version));
     } else if (strcmp(interface, "zxdg_decoration_manager_v1") == 0) {
         d->decoration_manager = wl_registry_bind(d->registry, id, &zxdg_decoration_manager_v1_interface, 1);
     } else if (strcmp(interface, "org_kde_kwin_server_decoration_manager") == 0) {
