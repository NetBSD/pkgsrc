$NetBSD: patch-libs_aaf_aaf_LibCFB.h,v 1.2 2025/01/31 17:15:11 wiz Exp $

Fix build on NetBSD.

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
