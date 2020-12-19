$NetBSD: patch-video_out_wayland__common.c,v 1.5 2020/12/19 11:27:51 leot Exp $

Allow building on systems without evdev.

--- video/out/wayland_common.c.orig	2020-11-22 17:46:28.000000000 +0000
+++ video/out/wayland_common.c
@@ -19,7 +19,15 @@
 #include <limits.h>
 #include <poll.h>
 #include <unistd.h>
+#ifdef HAVE_LINUX_INPUT_EVENT_CODES 
 #include <linux/input-event-codes.h>
+#else
+#define BTN_LEFT	(0x110)
+#define BTN_RIGHT	(0x111)
+#define BTN_MIDDLE	(0x112)
+#define BTN_SIDE	(0x113)
+#define BTN_EXTRA	(0x114)
+#endif
 #include <time.h>
 #include "common/msg.h"
 #include "options/m_config.h"
