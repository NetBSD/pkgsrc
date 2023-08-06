$NetBSD: patch-src_core_control_DeviceListHelper.cpp,v 1.1 2023/08/06 11:59:42 yhardy Exp $

This check seems to skip devices that are reasonable to include (on NetBSD), so rather
list all devices and let the user manage them.

--- src/core/control/DeviceListHelper.cpp.orig	2023-07-29 21:28:24.000000000 +0000
+++ src/core/control/DeviceListHelper.cpp
@@ -28,7 +28,7 @@ void addDevicesToList(std::vector<InputD
         if (GDK_SOURCE_KEYBOARD == gdk_device_get_source(&dev)) {
             continue;
         }
-        if (gdk_device_get_vendor_id(&dev) == nullptr && gdk_device_get_product_id(&dev) == nullptr) {
+        if (gdk_device_get_device_type(&dev) == GDK_DEVICE_TYPE_MASTER) {
             continue;
         }
         if (ignoreTouchDevices && GDK_SOURCE_TOUCHSCREEN == gdk_device_get_source(&dev)) {
