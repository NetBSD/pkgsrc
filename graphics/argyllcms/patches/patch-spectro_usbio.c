$NetBSD: patch-spectro_usbio.c,v 1.1 2023/11/17 17:37:48 jakllsch Exp $

Attempt to add NetBSD support to spectro/usbio

--- spectro/usbio.c.orig	2023-10-23 00:56:17.000000000 +0000
+++ spectro/usbio.c
@@ -96,7 +96,7 @@ static int icoms_usb_wait_io(
 # include "usbio_ox.c"
 #endif
 #if defined(UNIX_X11)
-# if defined(__FreeBSD__) || defined(__OpenBSD__)
+#  if defined(__FreeBSD__) || defined (__NetBSD__) || defined(__OpenBSD__)
 #  include "usbio_bsd.c"
 # else
 #  include "usbio_lx.c"
