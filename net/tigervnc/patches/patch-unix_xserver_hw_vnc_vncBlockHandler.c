$NetBSD: patch-unix_xserver_hw_vnc_vncBlockHandler.c,v 1.1 2021/05/16 21:06:43 wiz Exp $

--- unix/xserver/hw/vnc/vncBlockHandler.c.orig	2018-07-16 14:08:55.000000000 +0000
+++ unix/xserver/hw/vnc/vncBlockHandler.c
@@ -17,14 +17,14 @@
  * USA.
  */
 
+#include <X11/Xpoll.h>
+
 #ifdef HAVE_DIX_CONFIG_H
 #include <dix-config.h>
 #endif
 
 #include <errno.h>
 
-#include <X11/Xpoll.h>
-
 #include "os.h"
 #include "dix.h"
 #include "scrnintstr.h"
