$NetBSD: patch-video_out_wayland__common.c,v 1.6 2021/11/01 17:39:26 leot Exp $

Allow building on systems without evdev.

--- video/out/wayland_common.c.orig	2021-11-01 14:44:39.000000000 +0000
+++ video/out/wayland_common.c
@@ -17,7 +17,15 @@
 
 #include <errno.h>
 #include <limits.h>
+#ifdef HAVE_LINUX_INPUT_EVENT_CODES 
 #include <linux/input-event-codes.h>
+#else
+#define BTN_LEFT	(0x110)
+#define BTN_RIGHT	(0x111)
+#define BTN_MIDDLE	(0x112)
+#define BTN_SIDE	(0x113)
+#define BTN_EXTRA	(0x114)
+#endif
 #include <poll.h>
 #include <time.h>
 #include <unistd.h>
