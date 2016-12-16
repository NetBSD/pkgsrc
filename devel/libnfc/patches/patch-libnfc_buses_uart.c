$NetBSD: patch-libnfc_buses_uart.c,v 1.1 2016/12/16 08:11:55 manu Exp $

NetBSD serial ports

--- libnfc/buses/uart.c.orig	2016-12-14 10:59:45.000000000 +0100
+++ libnfc/buses/uart.c	2016-12-14 11:00:35.000000000 +0100
@@ -76,8 +76,10 @@
 #  if defined(__APPLE__)
 const char *serial_ports_device_radix[] = { "tty.SLAB_USBtoUART", "tty.usbserial-", NULL };
 #  elif defined (__FreeBSD__) || defined (__OpenBSD__) || defined(__FreeBSD_kernel__)
 const char *serial_ports_device_radix[] = { "cuaU", "cuau", NULL };
+#  elif defined (__NetBSD__)
+const char *serial_ports_device_radix[] = { "tty0", "ttyC", "ttyS", "ttyU", "ttyY" , NULL };
 #  elif defined (__linux__)
 const char *serial_ports_device_radix[] = { "ttyUSB", "ttyS", "ttyACM", "ttyAMA", "ttyO", NULL };
 #  else
 #    error "Can't determine serial string for your system"
