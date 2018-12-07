$NetBSD: patch-src_mame_video_xavix.cpp,v 1.2 2018/12/07 22:09:16 wiz Exp $

For sin, atan in std::.
https://github.com/mamedev/mame/pull/4379

--- src/mame/video/xavix.cpp.orig	2018-11-27 19:12:23.000000000 +0000
+++ src/mame/video/xavix.cpp
@@ -7,6 +7,8 @@
 // #define VERBOSE 1
 #include "logmacro.h"
 
+#include <cmath>
+
 inline void xavix_state::set_data_address(int address, int bit)
 {
 	m_tmp_dataaddress = address;
