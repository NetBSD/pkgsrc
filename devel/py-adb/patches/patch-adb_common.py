$NetBSD: patch-adb_common.py,v 1.1 2020/04/03 23:06:35 nia Exp $

This fails on NetBSD too.

--- adb/common.py.orig	2018-05-31 08:43:12.000000000 +0000
+++ adb/common.py
@@ -118,6 +118,7 @@ class UsbHandle(object):
         iface_number = self._setting.getNumber()
         try:
             if (platform.system() != 'Windows'
+                    and platform.system() != 'NetBSD'
                     and handle.kernelDriverActive(iface_number)):
                 handle.detachKernelDriver(iface_number)
         except libusb1.USBError as e:
