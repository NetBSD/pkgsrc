$NetBSD: patch-client_Wayland_wlfreerdp.c,v 1.1 2022/08/06 08:02:27 nia Exp $

Support building Wayland components on non-Linux.

--- client/Wayland/wlfreerdp.c.orig	2021-03-15 12:29:35.000000000 +0000
+++ client/Wayland/wlfreerdp.c
@@ -31,7 +31,9 @@
 #include <freerdp/utils/signal.h>
 #include <freerdp/locale/keyboard.h>
 
+#ifdef __linux
 #include <linux/input.h>
+#endif
 
 #include <uwac/uwac.h>
 
