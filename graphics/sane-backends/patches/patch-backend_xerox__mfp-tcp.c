$NetBSD: patch-backend_xerox__mfp-tcp.c,v 1.1 2011/07/31 20:05:58 gls Exp $

Fix for pkg/45196. Add sys/socket.h header.

--- backend/xerox_mfp-tcp.c.orig	2010-12-01 23:49:58.000000000 +0000
+++ backend/xerox_mfp-tcp.c
@@ -28,6 +28,10 @@
 #include <errno.h>
 #include <sys/time.h>
 
+#ifdef HAVE_SYS_SOCKET_H
+#include <sys/socket.h>
+#endif
+
 #include "sane/saneopts.h"
 #include "sane/sanei_scsi.h"
 #include "sane/sanei_usb.h"
