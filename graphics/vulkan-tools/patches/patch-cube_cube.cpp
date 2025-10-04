$NetBSD: patch-cube_cube.cpp,v 1.2 2025/10/04 12:39:56 tnn Exp $

Allow building on NetBSD.

--- cube/cube.cpp.orig	2025-10-04 12:29:34.996749955 +0000
+++ cube/cube.cpp
@@ -40,7 +40,9 @@
 #include "xcb_loader.h"
 #endif
 #if defined(VK_USE_PLATFORM_WAYLAND_KHR)
+#if defined(__linux__)
 #include <linux/input.h>
+#endif
 #include "wayland_loader.h"
 #endif
 #if defined(VK_USE_PLATFORM_FUCHSIA)
@@ -578,9 +580,11 @@ static void pointer_handle_motion(void *
 static void pointer_handle_button(void *data, struct wl_pointer *wl_pointer, uint32_t serial, uint32_t time, uint32_t button,
                                   uint32_t state) {
     Demo &demo = *static_cast<Demo *>(data);
+#if defined(__linux__)
     if (button == BTN_LEFT && state == WL_POINTER_BUTTON_STATE_PRESSED) {
         xdg_toplevel_move(demo.window_toplevel, demo.seat, serial);
     }
+#endif
 }
 
 static void pointer_handle_axis(void *data, struct wl_pointer *wl_pointer, uint32_t time, uint32_t axis, wl_fixed_t value) {}
@@ -600,6 +604,7 @@ static void keyboard_handle_key(void *da
                                 uint32_t state) {
     if (state != WL_KEYBOARD_KEY_STATE_RELEASED) return;
     Demo &demo = *static_cast<Demo *>(data);
+#if defined(__linux__)
     switch (key) {
         case KEY_ESC:  // Escape
             demo.quit = true;
@@ -614,6 +619,7 @@ static void keyboard_handle_key(void *da
             demo.pause = !demo.pause;
             break;
     }
+#endif
 }
 
 static void keyboard_handle_modifiers(void *data, wl_keyboard *keyboard, uint32_t serial, uint32_t mods_depressed,
@@ -4133,7 +4139,7 @@ int WINAPI WinMain(HINSTANCE hInstance, 
 }
 
 #elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__QNX__) || defined(__GNU__) || \
-    defined(__Fuchsia__)
+    defined(__Fuchsia__) || defined(__NetBSD__)
 
 template <WsiPlatform WSI_PLATFORM>
 void Demo::execute() {
