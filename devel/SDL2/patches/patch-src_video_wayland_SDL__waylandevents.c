$NetBSD: patch-src_video_wayland_SDL__waylandevents.c,v 1.5 2020/04/05 16:22:42 nia Exp $

Allow building with Wayland on operating systems without evdev.

Fix wl_seat version fallback.

https://bugzilla.libsdl.org/show_bug.cgi?id=5074

--- src/video/wayland/SDL_waylandevents.c.orig	2020-03-11 01:36:18.000000000 +0000
+++ src/video/wayland/SDL_waylandevents.c
@@ -43,7 +43,15 @@
 #include "xdg-shell-client-protocol.h"
 #include "xdg-shell-unstable-v6-client-protocol.h"
 
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <linux/input.h>
+#else
+#define BTN_LEFT    (0x110)
+#define BTN_RIGHT   (0x111)
+#define BTN_MIDDLE  (0x112)
+#define BTN_SIDE    (0x113)
+#define BTN_EXTRA   (0x114)
+#endif
 #include <sys/select.h>
 #include <sys/mman.h>
 #include <poll.h>
@@ -437,7 +445,7 @@ pointer_handle_axis(void *data, struct w
 {
     struct SDL_WaylandInput *input = data;
 
-    if(wl_seat_interface.version >= 5)
+    if(wl_seat_get_version(input->seat) >= 5)
         pointer_handle_axis_common(input, SDL_FALSE, axis, value);
     else
         pointer_handle_axis_common_v1(input, time, axis, value);
@@ -998,7 +1006,7 @@ static const struct wl_data_device_liste
 };
 
 void
-Wayland_display_add_input(SDL_VideoData *d, uint32_t id)
+Wayland_display_add_input(SDL_VideoData *d, uint32_t id, uint32_t version)
 {
     struct SDL_WaylandInput *input;
     SDL_WaylandDataDevice *data_device = NULL;
@@ -1008,10 +1016,7 @@ Wayland_display_add_input(SDL_VideoData 
         return;
 
     input->display = d;
-    if (wl_seat_interface.version >= 5)
-        input->seat = wl_registry_bind(d->registry, id, &wl_seat_interface, 5);
-    else
-        input->seat = wl_registry_bind(d->registry, id, &wl_seat_interface, 1);
+    input->seat = wl_registry_bind(d->registry, id, &wl_seat_interface, SDL_min(5, version));
     input->sx_w = wl_fixed_from_int(0);
     input->sy_w = wl_fixed_from_int(0);
     d->input = input;
