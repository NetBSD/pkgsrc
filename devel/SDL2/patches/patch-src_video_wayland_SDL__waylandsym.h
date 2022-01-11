$NetBSD: patch-src_video_wayland_SDL__waylandsym.h,v 1.3 2022/01/11 13:02:37 nia Exp $

requiring wayland-1.20 is a bit _excessively_ new (builds with the
current version of pkgsrc fail because wl_proxy_marshal_flags is not defined.

SDL is not even using these symbols.

--- src/video/wayland/SDL_waylandsym.h.orig	2022-01-08 02:29:52.000000000 +0000
+++ src/video/wayland/SDL_waylandsym.h
@@ -84,9 +84,11 @@ SDL_WAYLAND_MODULE(WAYLAND_CLIENT_1_18)
 SDL_WAYLAND_SYM(void, wl_proxy_set_tag, (struct wl_proxy *, const char * const *))
 SDL_WAYLAND_SYM(const char * const *, wl_proxy_get_tag, (struct wl_proxy *))
 
+#if 0
 SDL_WAYLAND_MODULE(WAYLAND_CLIENT_1_20)
 SDL_WAYLAND_SYM(struct wl_proxy*, wl_proxy_marshal_flags, (struct wl_proxy *proxy, uint32_t opcode, const struct wl_interface *interfac, uint32_t version, uint32_t flags, ...))
 SDL_WAYLAND_SYM(struct wl_proxy*, wl_proxy_marshal_array_flags, (struct wl_proxy *proxy, uint32_t opcode, const struct wl_interface *interface, uint32_t version,  uint32_t flags, union wl_argument *args))
+#endif
 
 SDL_WAYLAND_INTERFACE(wl_seat_interface)
 SDL_WAYLAND_INTERFACE(wl_surface_interface)
