$NetBSD: patch-libgphoto2__port_libusb1_libusb1.c,v 1.1 2024/03/19 09:58:13 wiz Exp $

Workaround for PR 56666 and PR 58048.
"gp_port_set_error [gphoto2-port.c:1190](0): Could not query kernel driver of device."

--- libgphoto2_port/libusb1/libusb1.c.orig	2024-03-19 09:54:46.384960053 +0000
+++ libgphoto2_port/libusb1/libusb1.c
@@ -699,6 +699,10 @@ gp_libusb1_queue_interrupt_urbs (GPPort 
 	unsigned int i;
 	int ret = 0;
 
+#ifdef __NetBSD__
+	return 0; /* not working yet */
+#endif
+
 	/* no interrupt endpoint */
 	if (port->settings.usb.intep == -1)
 		return GP_OK;
