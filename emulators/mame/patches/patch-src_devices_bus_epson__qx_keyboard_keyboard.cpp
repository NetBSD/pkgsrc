$NetBSD: patch-src_devices_bus_epson__qx_keyboard_keyboard.cpp,v 1.1 2022/10/30 21:13:43 wiz Exp $

Fix build without pre-compiled headers.
https://github.com/mamedev/mame/commit/de835f1b027edc14b866093f4ffaf549e133a329

--- src/devices/bus/epson_qx/keyboard/keyboard.cpp.orig	2022-10-26 22:12:58.000000000 +0000
+++ src/devices/bus/epson_qx/keyboard/keyboard.cpp
@@ -6,14 +6,17 @@
 
 ***************************************************************************/
 
-#include "cpu/mcs48/mcs48.h"
 #include "emu.h"
 #include "keyboard.h"
+
 #include "matrix.h"
 
+#include "cpu/mcs48/mcs48.h"
+
 #include "qx10ascii.lh"
 #include "qx10hasci.lh"
 
+
 //**************************************************************************
 //  DEVICE DEFINITIONS
 //**************************************************************************
@@ -22,6 +25,7 @@ DEFINE_DEVICE_TYPE(EPSON_QX_KEYBOARD_POR
 DEFINE_DEVICE_TYPE(QX10_KEYBOARD_HASCI, bus::epson_qx::keyboard::qx10_keyboard_hasci, "qx10_keyboard_hasci", "Epson QX-10 Keyboard (HASCI)")
 DEFINE_DEVICE_TYPE(QX10_KEYBOARD_ASCII, bus::epson_qx::keyboard::qx10_keyboard_ascii, "qx10_keyboard_ascii", "Epson QX-10 Keyboard (ASCII)")
 
+
 namespace bus::epson_qx::keyboard {
 
 //**************************************************************************
