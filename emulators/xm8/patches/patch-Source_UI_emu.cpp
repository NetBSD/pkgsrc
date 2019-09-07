$NetBSD: patch-Source_UI_emu.cpp,v 1.1 2019/09/07 00:36:34 tsutsui Exp $

- change rom file directory to ~/.local/share/retro_pc_pi/xm8/rom

--- Source/UI/emu.cpp.orig	2015-04-20 05:10:30.000000000 +0000
+++ Source/UI/emu.cpp
@@ -8,6 +8,7 @@
 */
 
 #include "common.h"
+#include "classes.h"
 #include "emu.h"
 #include "emu_sdl.h"
 
