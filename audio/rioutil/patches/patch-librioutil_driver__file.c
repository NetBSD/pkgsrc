$NetBSD: patch-librioutil_driver__file.c,v 1.1 2019/12/31 12:10:20 schmonz Exp $

Support DragonFly.

--- librioutil/driver_file.c.orig	2019-05-14 19:24:11.000000000 +0000
+++ librioutil/driver_file.c
@@ -32,7 +32,7 @@
 char driver_method[] = "device file";
 
 /* Duplicated from rio_usb.h */
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 #define RIO_RECV_COMMAND _IOWR('U', 201, struct RioCommand)
 #else
 #define RIO_RECV_COMMAND 0x2
@@ -42,7 +42,7 @@ char driver_method[] = "device file";
 #ifdef linux
 #include <linux/usb.h>
 #define RIODEVICE  "/dev/usb/rio"
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 #define RIODEVICE "/dev/urio"
 #elif defined(__NetBSD__)
 #define RIODEVICE "/dev/urio"
