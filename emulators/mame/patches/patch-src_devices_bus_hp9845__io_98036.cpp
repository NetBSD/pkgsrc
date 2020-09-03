$NetBSD: patch-src_devices_bus_hp9845__io_98036.cpp,v 1.1 2020/09/03 07:47:42 wiz Exp $

Fix build without pre-compiled headers.
https://github.com/mamedev/mame/commit/69406ddcc71272c30a824dd6f19f5d447732ed42

--- src/devices/bus/hp9845_io/98036.cpp.orig	2020-08-25 01:03:34.000000000 +0000
+++ src/devices/bus/hp9845_io/98036.cpp
@@ -11,6 +11,7 @@
 
 *********************************************************************/
 
+#include "emu.h"
 #include "98036.h"
 
 // Debugging
