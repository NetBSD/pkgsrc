$NetBSD: patch-src_video_wayland_SDL__waylandevents.c,v 1.2 2019/10/29 22:46:39 nia Exp $

Allow building with Wayland on operating systems without evdev.

--- src/video/wayland/SDL_waylandevents.c.orig	2019-07-25 04:32:36.000000000 +0000
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
