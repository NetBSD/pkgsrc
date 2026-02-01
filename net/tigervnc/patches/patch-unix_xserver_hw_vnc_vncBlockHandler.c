$NetBSD: patch-unix_xserver_hw_vnc_vncBlockHandler.c,v 1.2 2026/02/01 19:18:57 wiz Exp $

--- unix/xserver/hw/vnc/vncBlockHandler.c.orig	2026-01-23 10:05:49.000000000 +0000
+++ unix/xserver/hw/vnc/vncBlockHandler.c
@@ -17,13 +17,13 @@
  * USA.
  */
 
+#include <X11/Xpoll.h>
+
 #ifdef HAVE_DIX_CONFIG_H
 #include <dix-config.h>
 #endif
 
 #include <errno.h>
-
-#include <X11/Xpoll.h>
 
 #include "os.h"
 #include "dix.h"
