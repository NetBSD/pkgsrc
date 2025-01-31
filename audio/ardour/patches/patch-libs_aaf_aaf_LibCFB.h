$NetBSD: patch-libs_aaf_aaf_LibCFB.h,v 1.3 2025/01/31 22:01:23 wiz Exp $

Fix build on NetBSD.
https://tracker.ardour.org/view.php?id=9886

--- libs/aaf/aaf/LibCFB.h.orig	2024-02-04 02:25:00.306525205 +0000
+++ libs/aaf/aaf/LibCFB.h
@@ -37,6 +37,8 @@
 #elif defined(_WIN32)
 #include <windows.h> // MAX_PATH
 #include <limits.h>
+#else
+#include <limits.h>
 #endif
 
 /**
