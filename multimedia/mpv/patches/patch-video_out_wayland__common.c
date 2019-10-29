$NetBSD: patch-video_out_wayland__common.c,v 1.3 2019/10/29 22:46:39 nia Exp $

Allow building on systems without evdev.

--- video/out/wayland_common.c.orig	2019-10-25 13:08:15.000000000 +0000
+++ video/out/wayland_common.c
@@ -19,7 +19,13 @@
 #include <limits.h>
 #include <poll.h>
 #include <unistd.h>
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <linux/input.h>
+#else
+#define BTN_LEFT	(0x110)
+#define BTN_RIGHT	(0x111)
+#define BTN_MIDDLE	(0x112)
+#endif
 #include <time.h>
 #include "common/msg.h"
 #include "options/m_config.h"
