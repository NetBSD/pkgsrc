$NetBSD: patch-lib_cximage-6.0_CxImage_DllInterface.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- lib/cximage-6.0/CxImage/DllInterface.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ lib/cximage-6.0/CxImage/DllInterface.cpp
@@ -2,10 +2,13 @@
 #include "ximage.h"
 #include "ximajpg.h"
 
-#if defined(_LINUX) || defined(__APPLE__)
+#if defined(_LINUX) || defined(__APPLE__) || defined(__NetBSD__)
 #include <unistd.h>
 #include <sys/stat.h>
 #include <errno.h>
+#if defined(__NetBSD__)
+#include <strings.h>
+#endif
 #define strcmpi strcasecmp
 #else //win32
 #include <sys/types.h>
