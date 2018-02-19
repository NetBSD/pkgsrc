$NetBSD: patch-port_cpl__conv.cpp,v 1.1 2018/02/19 12:05:17 ryoon Exp $

* Fix build under NetBSD

--- port/cpl_conv.cpp.orig	2017-11-20 10:45:32.000000000 +0000
+++ port/cpl_conv.cpp
@@ -45,7 +45,7 @@
 #endif
 
 // For atoll (at least for NetBSD)
-#define _ISOC99_SOURCE
+#define _NETBSD_SOURCE
 
 #ifdef MSVC_USE_VLD
 #include <vld.h>
