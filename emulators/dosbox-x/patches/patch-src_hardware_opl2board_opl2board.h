$NetBSD: patch-src_hardware_opl2board_opl2board.h,v 1.1 2025/05/16 21:46:43 nia Exp $

Add missing include for uint8_t.

--- src/hardware/opl2board/opl2board.h.orig	2025-05-16 15:18:35.963407265 +0000
+++ src/hardware/opl2board/opl2board.h
@@ -1,4 +1,5 @@
 #include "../serialport/libserial.h"
+#include <stdint.h>
 
 #ifndef OPL2_AUDIO_BOARD
 	#define OPL2_AUDIO_BOARD
