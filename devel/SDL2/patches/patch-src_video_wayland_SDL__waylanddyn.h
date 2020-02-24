$NetBSD: patch-src_video_wayland_SDL__waylanddyn.h,v 1.1 2020/02/24 11:55:36 nia Exp $

https://bugzilla.libsdl.org/show_bug.cgi?id=4924

--- src/video/wayland/SDL_waylanddyn.h.orig	2019-07-25 04:32:37.000000000 +0000
+++ src/video/wayland/SDL_waylanddyn.h
@@ -74,6 +74,7 @@ void SDL_WAYLAND_UnloadSymbols(void);
 #define wl_proxy_marshal (*WAYLAND_wl_proxy_marshal)
 #define wl_proxy_set_user_data (*WAYLAND_wl_proxy_set_user_data)
 #define wl_proxy_get_user_data (*WAYLAND_wl_proxy_get_user_data)
+#define wl_proxy_get_version (*WAYLAND_wl_proxy_get_version)
 #define wl_proxy_add_listener (*WAYLAND_wl_proxy_add_listener)
 #define wl_proxy_marshal_constructor (*WAYLAND_wl_proxy_marshal_constructor)
 #define wl_proxy_marshal_constructor_versioned (*WAYLAND_wl_proxy_marshal_constructor_versioned)
