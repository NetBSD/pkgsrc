$NetBSD: patch-cube_cube.c,v 1.1 2025/10/04 12:39:56 tnn Exp $

Allow building on NetBSD.

--- cube/cube.c.orig	2025-10-04 12:29:59.680457395 +0000
+++ cube/cube.c
@@ -44,7 +44,9 @@
 #include "xcb_loader.h"
 #endif
 #if defined(VK_USE_PLATFORM_WAYLAND_KHR)
+#if defined(__linux__)
 #include <linux/input.h>
+#endif
 #include "wayland_loader.h"
 #endif
 
@@ -3581,9 +3583,11 @@ static void pointer_handle_motion(void *
 static void pointer_handle_button(void *data, struct wl_pointer *wl_pointer, uint32_t serial, uint32_t time, uint32_t button,
                                   uint32_t state) {
     struct demo *demo = data;
+#if defined(__linux__)
     if (button == BTN_LEFT && state == WL_POINTER_BUTTON_STATE_PRESSED) {
         xdg_toplevel_move(demo->xdg_toplevel, demo->seat, serial);
     }
+#endif
 }
 
 static void pointer_handle_axis(void *data, struct wl_pointer *wl_pointer, uint32_t time, uint32_t axis, wl_fixed_t value) {}
@@ -3603,6 +3607,7 @@ static void keyboard_handle_key(void *da
                                 uint32_t state) {
     if (state != WL_KEYBOARD_KEY_STATE_RELEASED) return;
     struct demo *demo = data;
+#if defined(__linux__)
     switch (key) {
         case KEY_ESC:  // Escape
             demo->quit = true;
@@ -3617,6 +3622,7 @@ static void keyboard_handle_key(void *da
             demo->pause = !demo->pause;
             break;
     }
+#endif
 }
 
 static void keyboard_handle_modifiers(void *data, struct wl_keyboard *keyboard, uint32_t serial, uint32_t mods_depressed,
@@ -5079,7 +5085,7 @@ void android_main(struct android_app *ap
         }
     }
 }
-#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QNX__) || defined(__GNU__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QNX__) || defined(__GNU__) || defined(__NetBSD__)
 int main(int argc, char **argv) {
     struct demo demo;
 
