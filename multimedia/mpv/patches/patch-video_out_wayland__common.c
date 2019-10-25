$NetBSD: patch-video_out_wayland__common.c,v 1.2 2019/10/25 14:35:56 leot Exp $

Allow building on systems without evdev.

--- video/out/wayland_common.c.orig	2019-10-25 13:08:15.000000000 +0000
+++ video/out/wayland_common.c
@@ -19,7 +19,13 @@
 #include <limits.h>
 #include <poll.h>
 #include <unistd.h>
+#if defined(__linux) || defined(__FreeBSD__)
 #include <linux/input.h>
+#else
+#define BTN_LEFT	(0)
+#define BTN_MIDDLE	(1)
+#define BTN_RIGHT	(2)
+#endif
 #include <time.h>
 #include "common/msg.h"
 #include "options/m_config.h"
