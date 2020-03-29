$NetBSD: patch-src_scripting_flash_display_flashdisplay.h,v 1.1 2020/03/29 01:04:07 joerg Exp $

bimap.hpp needs split_member.hpp with Boost 1.72.

--- src/scripting/flash/display/flashdisplay.h.orig	2020-03-28 21:01:36.935735038 +0000
+++ src/scripting/flash/display/flashdisplay.h
@@ -20,6 +20,7 @@
 #ifndef SCRIPTING_FLASH_DISPLAY_FLASHDISPLAY_H
 #define SCRIPTING_FLASH_DISPLAY_FLASHDISPLAY_H 1
 
+#include <boost/serialization/split_member.hpp>
 #include <boost/bimap.hpp>
 #include "compat.h"
 
