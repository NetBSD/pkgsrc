$NetBSD: patch-src_video_wayland_SDL__waylandsym.h,v 1.1 2020/02/24 11:55:36 nia Exp $

https://bugzilla.libsdl.org/show_bug.cgi?id=4924

--- src/video/wayland/SDL_waylandsym.h.orig	2019-07-25 04:32:36.000000000 +0000
+++ src/video/wayland/SDL_waylandsym.h
@@ -40,6 +40,7 @@ SDL_WAYLAND_SYM(void, wl_proxy_destroy, 
 SDL_WAYLAND_SYM(int, wl_proxy_add_listener, (struct wl_proxy *, void (**)(void), void *))
 SDL_WAYLAND_SYM(void, wl_proxy_set_user_data, (struct wl_proxy *, void *))
 SDL_WAYLAND_SYM(void *, wl_proxy_get_user_data, (struct wl_proxy *))
+SDL_WAYLAND_SYM(uint32_t, wl_proxy_get_version, (struct wl_proxy *))
 SDL_WAYLAND_SYM(uint32_t, wl_proxy_get_id, (struct wl_proxy *))
 SDL_WAYLAND_SYM(const char *, wl_proxy_get_class, (struct wl_proxy *))
 SDL_WAYLAND_SYM(void, wl_proxy_set_queue, (struct wl_proxy *, struct wl_event_queue *))
