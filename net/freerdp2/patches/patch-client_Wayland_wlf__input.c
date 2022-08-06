$NetBSD: patch-client_Wayland_wlf__input.c,v 1.1 2022/08/06 08:02:27 nia Exp $

Support building Wayland components on non-Linux.

--- client/Wayland/wlf_input.c.orig	2021-03-15 12:29:35.000000000 +0000
+++ client/Wayland/wlf_input.c
@@ -19,7 +19,17 @@
  */
 
 #include <stdlib.h>
+#ifdef __linux
 #include <linux/input.h>
+#else
+#ifndef BTN_LEFT
+#define BTN_LEFT	(0x110)
+#define BTN_RIGHT	(0x111)
+#define BTN_MIDDLE	(0x112)
+#define BTN_SIDE	(0x113)
+#define BTN_EXTRA	(0x114)
+#endif
+#endif
 
 #include <freerdp/locale/keyboard.h>
 #include <freerdp/client/rdpei.h>
