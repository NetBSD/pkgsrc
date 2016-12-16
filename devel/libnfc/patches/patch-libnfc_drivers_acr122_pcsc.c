$NetBSD: patch-libnfc_drivers_acr122_pcsc.c,v 1.1 2016/12/16 08:11:55 manu Exp $

NetBSD definition for CCID ioctl

--- libnfc/drivers/acr122_pcsc.c.orig	2016-12-14 15:03:27.000000000 +0100
+++ libnfc/drivers/acr122_pcsc.c	2016-12-14 15:04:21.000000000 +0100
@@ -58,9 +58,9 @@
 #if defined (_WIN32)
 #  define IOCTL_CCID_ESCAPE_SCARD_CTL_CODE SCARD_CTL_CODE(3500)
 #elif defined(__APPLE__)
 #  define IOCTL_CCID_ESCAPE_SCARD_CTL_CODE (((0x31) << 16) | ((3500) << 2))
-#elif defined (__FreeBSD__) || defined (__OpenBSD__)
+#elif defined (__FreeBSD__) || defined (__OpenBSD__) || defined (__NetBSD__)
 #  define IOCTL_CCID_ESCAPE_SCARD_CTL_CODE (((0x31) << 16) | ((3500) << 2))
 #elif defined (__linux__)
 #  include <reader.h>
 // Escape IOCTL tested successfully:
