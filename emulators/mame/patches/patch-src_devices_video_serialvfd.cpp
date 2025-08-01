$NetBSD: patch-src_devices_video_serialvfd.cpp,v 1.1 2025/08/01 18:31:11 wiz Exp $

https://github.com/mamedev/mame/commit/95f7d841988286de21c03f48bfcce45b1aed7bc6

--- src/devices/video/serialvfd.cpp.orig	2025-07-30 22:06:29.000000000 +0000
+++ src/devices/video/serialvfd.cpp
@@ -1,8 +1,8 @@
 // license:BSD-3-Clause
 // copyright-holders: NaokiS
 
-#include "serialvfd.h"
 #include "emu.h"
+#include "serialvfd.h"
 
 #define LOG_VFD     (1U << 1)
 //#define VERBOSE     ( LOG_VFD )
