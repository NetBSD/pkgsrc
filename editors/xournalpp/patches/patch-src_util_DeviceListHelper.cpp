$NetBSD: patch-src_util_DeviceListHelper.cpp,v 1.2 2021/07/22 12:10:46 yhardy Exp $

This check seems to skip devices that are reasonable to include (on NetBSD), so rather
list all devices and let the user manage them.

--- src/util/DeviceListHelper.cpp.orig	2021-07-18 21:18:39.000000000 +0000
+++ src/util/DeviceListHelper.cpp
@@ -26,7 +26,7 @@ void addDevicesToList(std::vector<InputD
             devList = devList->next;
             continue;
         }
-        if (gdk_device_get_vendor_id(dev) == nullptr && gdk_device_get_product_id(dev) == nullptr) {
+        if (gdk_device_get_device_type(dev) == GDK_DEVICE_TYPE_MASTER) {
             // Skip core pointer
             devList = devList->next;
             continue;
