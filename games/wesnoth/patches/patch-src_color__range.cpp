$NetBSD: patch-src_color__range.cpp,v 1.2 2023/08/23 08:01:06 adam Exp $

Add missing include.

--- src/color_range.cpp.orig	2020-04-14 20:36:13.908481410 +0000
+++ src/color_range.cpp
@@ -24,6 +24,7 @@
 #include "map/map.hpp"
 
 #include <iomanip>
+#include <sstream>
 #include <unordered_set>
 
 color_range_map recolor_range(const color_range& new_range, const std::vector<color_t>& old_rgb)
