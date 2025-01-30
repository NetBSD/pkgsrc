$NetBSD: patch-src_hamlib.cpp,v 1.4 2025/01/30 20:22:43 wiz Exp $

Fix build with hamlib 4.2.

--- src/hamlib.cpp.orig	2025-01-30 20:21:17.114194427 +0000
+++ src/hamlib.cpp
@@ -21,6 +21,10 @@
 //==========================================================================
 #include <hamlib.h>
 
+#ifndef FILPATHLEN
+#define FILPATHLEN HAMLIB_FILPATHLEN
+#endif
+
 #include <vector>
 #include <algorithm>
 
