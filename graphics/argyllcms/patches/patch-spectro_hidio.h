$NetBSD: patch-spectro_hidio.h,v 1.2 2026/02/11 02:41:15 jakllsch Exp $

Attempt to add NetBSD support to spectro/hidio

--- spectro/hidio.h.orig	2026-02-09 22:25:25.000000000 +0000
+++ spectro/hidio.h
@@ -80,6 +80,15 @@ struct hid_idevice {
     int bread;            				/* Bytes read by callback */
 #endif	/* MAC_OS_X_VERSION_MIN_REQUIRED < 1060 */
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
 	char *SerialNumber;		/* If not-NULL, USB serial number string */
 };
 
