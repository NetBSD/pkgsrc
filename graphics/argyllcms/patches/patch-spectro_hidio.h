$NetBSD: patch-spectro_hidio.h,v 1.1 2023/11/17 17:37:48 jakllsch Exp $

Attempt to add NetBSD support to spectro/hidio

--- spectro/hidio.h.orig	2023-10-23 00:56:17.000000000 +0000
+++ spectro/hidio.h
@@ -80,6 +80,15 @@ struct hid_idevice {
     int bread;            				/* Bytes read by callback */
 #endif	/* __MAC_OS_X_VERSION_MAX_ALLOWED < 1060 */
 #endif
+#if defined(UNIX_X11)
+#if defined(__NetBSD__)
+	char *dpath;				/* Device path */
+	/* Stuff setup when device is open: */
+	int fd;					/* file descriptor */
+	int rchunk;
+	int wchunk;
+#endif
+#endif
 };
 
 /* Cleanup and then free an hidd entry */
