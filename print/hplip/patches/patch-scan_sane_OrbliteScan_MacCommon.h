$NetBSD: patch-scan_sane_OrbliteScan_MacCommon.h,v 1.1 2022/08/26 03:08:28 khorben Exp $

--- scan/sane/OrbliteScan/MacCommon.h.orig	2019-12-10 05:00:30.000000000 +0000
+++ scan/sane/OrbliteScan/MacCommon.h
@@ -1,12 +1,10 @@
 #ifndef H_MacCommon
 #define H_MacCommon
 
-#ifndef __linux__
+#ifdef __APPLE__
 #include <CoreFoundation/CFPlugInCOM.h>
 #define __CFPlugInCOM_Included__
-#endif
-
-#ifdef __linux__
+#else
 #    include "LinuxCommon.h"
 #endif
 
