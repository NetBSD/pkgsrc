$NetBSD: patch-backend_xerox__mfp-tcp.c,v 1.2 2012/12/10 12:06:51 ryoon Exp $

Fix for pkg/45196. Add sys/socket.h header.

--- backend/xerox_mfp-tcp.c.orig	2011-11-21 20:17:48.000000000 +0000
+++ backend/xerox_mfp-tcp.c
@@ -32,6 +32,10 @@
 #include <sys/socket.h>
 #endif
 
+#ifdef HAVE_SYS_SOCKET_H
+#include <sys/socket.h>
+#endif
+
 #include "sane/saneopts.h"
 #include "sane/sanei_scsi.h"
 #include "sane/sanei_usb.h"
