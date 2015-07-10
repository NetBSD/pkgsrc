$NetBSD: patch-mtx.h,v 1.2 2015/07/10 13:33:41 bouyer Exp $

--- mtx.h.orig	2015-07-08 16:23:01.000000000 +0200
+++ mtx.h	2015-07-08 16:24:24.000000000 +0200
@@ -68,6 +68,13 @@
 #  include <sys/param.h>
 #endif
 
+#ifdef __NetBSD__
+/* use NetBSD's scsiio interface */
+#include <sys/scsiio.h>
+typedef int DEVICE_TYPE;
+#endif
+
+
 /* Now greatly modified to use GNU Autoconf stuff: */
 /* If we use the 'sg' interface, like Linux, do this: */
 #if HAVE_SCSI_SG_H
