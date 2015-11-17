$NetBSD: patch-xbmc_peripherals_bus_PeripheralBusUSB.h,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/peripherals/bus/PeripheralBusUSB.h.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/peripherals/bus/PeripheralBusUSB.h
@@ -31,6 +31,9 @@
 #elif defined(TARGET_FREEBSD) && defined(HAVE_LIBUSB)
 #define HAVE_PERIPHERAL_BUS_USB 1
 #include "linux/PeripheralBusUSBLibUSB.h"
+#elif defined(TARGET_NETBSD) && defined(HAVE_LIBUSB)
+#define HAVE_PERIPHERAL_BUS_USB 1
+#include "linux/PeripheralBusUSBLibUSB.h"
 #elif defined(TARGET_DARWIN)
 #define HAVE_PERIPHERAL_BUS_USB 1
 #include "osx/PeripheralBusUSB.h"
