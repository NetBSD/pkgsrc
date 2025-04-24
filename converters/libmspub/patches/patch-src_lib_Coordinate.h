$NetBSD: patch-src_lib_Coordinate.h,v 1.1 2025/04/24 14:17:23 tnn Exp $

Include <cstdint> for uint32_t.

--- src/lib/Coordinate.h.orig	2025-04-24 14:15:24.540385277 +0000
+++ src/lib/Coordinate.h
@@ -10,6 +10,7 @@
 #ifndef INCLUDED_COORDINATE_H
 #define INCLUDED_COORDINATE_H
 
+#include <cstdint>
 #include "MSPUBConstants.h"
 
 namespace libmspub
