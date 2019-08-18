$NetBSD: patch-video_out_wayland__common.c,v 1.1 2019/08/18 17:57:55 nia Exp $

Allow building on systems without evdev.

--- video/out/wayland_common.c.orig	2018-10-02 19:03:41.000000000 +0000
+++ video/out/wayland_common.c
@@ -16,8 +16,14 @@
  */
 
 #include <poll.h>
-#include <unistd.h>
+#if defined(__linux) || defined(__FreeBSD__)
 #include <linux/input.h>
+#else
+#define BTN_LEFT	(0)
+#define BTN_MIDDLE	(1)
+#define BTN_RIGHT	(2)
+#endif
+#include <unistd.h>
 #include "common/msg.h"
 #include "input/input.h"
 #include "input/keycodes.h"
