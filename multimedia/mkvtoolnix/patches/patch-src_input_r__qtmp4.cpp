$NetBSD: patch-src_input_r__qtmp4.cpp,v 1.1 2025/10/31 15:40:09 jperkin Exp $

Avoid ambiguous function call.

--- src/input/r_qtmp4.cpp.orig	2025-10-31 15:20:17.525150198 +0000
+++ src/input/r_qtmp4.cpp
@@ -1615,7 +1615,7 @@ qtmp4_reader_c::handle_display_matrix(qt
     dmx.yaw = 180;
   else
     return;
-  dmx.roll = 180 / M_PI * atan2(matrix[1][0], matrix[1][1]);
+  dmx.roll = 180 / M_PI * atan2((double)matrix[1][0], (double)matrix[1][1]);
   ignored = false;
 
   if (!dmx.yaw && !dmx.roll)
