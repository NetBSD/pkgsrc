$NetBSD: patch-spectro_usbio.c,v 1.2 2025/03/10 15:38:12 jakllsch Exp $

Attempt to add NetBSD support to spectro/usbio

--- spectro/usbio.c.orig	2024-09-24 22:29:21.000000000 +0000
+++ spectro/usbio.c
@@ -101,7 +101,7 @@ static int icoms_usb_wait_io(
 # include "usbio_ox.c"
 #endif
 #if defined(UNIX_X11)
-# if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__FreeBSD_kernel__)
+# if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__FreeBSD_kernel__) || defined (__NetBSD__)
 #  include "usbio_bsd.c"
 # else
 #  include "usbio_lx.c"
