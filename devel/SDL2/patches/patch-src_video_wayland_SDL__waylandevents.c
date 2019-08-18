$NetBSD: patch-src_video_wayland_SDL__waylandevents.c,v 1.1 2019/08/18 16:16:25 nia Exp $

Allow building with Wayland on operating systems without evdev.

--- src/video/wayland/SDL_waylandevents.c.orig	2019-07-25 04:32:36.000000000 +0000
+++ src/video/wayland/SDL_waylandevents.c
@@ -43,7 +43,15 @@
 #include "xdg-shell-client-protocol.h"
 #include "xdg-shell-unstable-v6-client-protocol.h"
 
+#ifdef __linux
 #include <linux/input.h>
+#else
+#define BTN_LEFT    (0)
+#define BTN_MIDDLE  (1)
+#define BTN_RIGHT   (2)
+#define BTN_SIDE    (3)
+#define BTN_EXTRA   (4)
+#endif
 #include <sys/select.h>
 #include <sys/mman.h>
 #include <poll.h>
