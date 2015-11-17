$NetBSD: patch-xbmc_peripherals_bus_linux_PeripheralBusUSBLibUSB.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- xbmc/peripherals/bus/linux/PeripheralBusUSBLibUSB.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ xbmc/peripherals/bus/linux/PeripheralBusUSBLibUSB.cpp
@@ -51,7 +51,7 @@ bool CPeripheralBusUSB::PerformDeviceSca
                              dev->config[0].bNumInterfaces > 0 && dev->config[0].interface[0].num_altsetting > 0) ?
                                  GetType(dev->config[0].interface[0].altsetting[0].bInterfaceClass) :
                                  GetType(dev->descriptor.bDeviceClass);
-#ifdef TARGET_FREEBSD
+#if defined(TARGET_FREEBSD) || defined(TARGET_NETBSD)
       result.m_strLocation = StringUtils::Format("%s", dev->filename);
 #else
       result.m_strLocation = StringUtils::Format("/bus%s/dev%s", bus->dirname, dev->filename);
