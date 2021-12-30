$NetBSD: patch-src_devices_bus_a2bus_cards.cpp,v 1.1 2021/12/30 11:18:34 wiz Exp $

Add missing PCH.
https://github.com/mamedev/mame/commit/0288a54ca21cb4e4d63e98507060af05abe59768

--- src/devices/bus/a2bus/cards.cpp.orig	2021-12-28 15:17:03.000000000 +0000
+++ src/devices/bus/a2bus/cards.cpp
@@ -9,6 +9,7 @@
 
 ***************************************************************************/
 
+#include "emu.h"
 #include "bus/a2bus/cards.h"
 
 #include "bus/a2bus/4play.h"
