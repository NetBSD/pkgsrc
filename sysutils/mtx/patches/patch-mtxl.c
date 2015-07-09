--- mtxl.c.orig	2015-07-08 16:25:32.000000000 +0200
+++ mtxl.c	2015-07-08 16:26:04.000000000 +0200
@@ -41,6 +41,10 @@
 
 /* First, do some SCSI routines: */
 
+#ifdef __NetBSD__
+#	include "scsi_netbsd.c"
+#endif
+
 /* the camlib is used on FreeBSD. */
 #if HAVE_CAMLIB_H
 #	include "scsi_freebsd.c"
