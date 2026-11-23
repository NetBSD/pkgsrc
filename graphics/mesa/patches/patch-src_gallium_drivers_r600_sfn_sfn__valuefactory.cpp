$NetBSD: patch-src_gallium_drivers_r600_sfn_sfn__valuefactory.cpp,v 1.1 2026/11/23 10:29:52 adam Exp $

Add missing include.

--- src/gallium/drivers/r600/sfn/sfn_valuefactory.cpp.orig	2025-04-30 18:31:25.098356269 +0000
+++ src/gallium/drivers/r600/sfn/sfn_valuefactory.cpp
@@ -12,6 +12,7 @@
 
 #include <algorithm>
 #include <iostream>
+#include <limits>
 #include <queue>
 #include <sstream>
 
