$NetBSD: patch-linux__driver_rio__usb.h,v 1.1 2019/12/31 12:10:20 schmonz Exp $

Support DragonFly.

--- linux_driver/rio_usb.h.orig	2019-05-14 19:24:11.000000000 +0000
+++ linux_driver/rio_usb.h
@@ -61,7 +61,7 @@ struct RioCommand {
 	int timeout;
 };
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
 #define RIO_SEND_COMMAND       _IOWR('U', 200, struct RioCommand)
 #define RIO_RECV_COMMAND       _IOWR('U', 201, struct RioCommand)
 #else
