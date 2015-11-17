$NetBSD: patch-lib_cximage-6.0_CxImage_ximainfo.cpp,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- lib/cximage-6.0/CxImage/ximainfo.cpp.orig	2015-10-19 06:31:15.000000000 +0000
+++ lib/cximage-6.0/CxImage/ximainfo.cpp
@@ -7,6 +7,9 @@
 #if defined(_LINUX) || defined(__APPLE__)
 #define _tcsnicmp(a,b,c) strcasecmp(a, b)
 #endif
+#if defined(__NetBSD__)
+#include <strings.h>
+#endif
 
 ////////////////////////////////////////////////////////////////////////////////
 /**
