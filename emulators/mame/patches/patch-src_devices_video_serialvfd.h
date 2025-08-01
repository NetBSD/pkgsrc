$NetBSD: patch-src_devices_video_serialvfd.h,v 1.1 2025/08/01 18:31:11 wiz Exp $

https://github.com/mamedev/mame/commit/95f7d841988286de21c03f48bfcce45b1aed7bc6

--- src/devices/video/serialvfd.h.orig	2025-07-30 22:06:29.000000000 +0000
+++ src/devices/video/serialvfd.h
@@ -14,8 +14,7 @@
 
 #pragma once
 
-class serial_vfd_device :
-	public device_t
+class serial_vfd_device : public device_t
 {
 public:
 	serial_vfd_device(const machine_config &mconfig, const char *tag, device_t *owner, uint32_t clock = 0);
@@ -51,7 +50,6 @@ private:
 	uint16_t m_buff[16];
 
 	void run_command();
-
 };
 
 DECLARE_DEVICE_TYPE(SERIAL_VFD, serial_vfd_device)
