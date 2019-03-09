$NetBSD: patch-port_cpl__conv.cpp,v 1.2 2019/03/09 01:54:59 gdt Exp $

Fix build under NetBSD
\todo Explain what is wrong.
\todo File ticket and get this fixed upstream.

--- port/cpl_conv.cpp.orig	2017-11-20 10:45:32.000000000 +0000
+++ port/cpl_conv.cpp
@@ -45,7 +45,7 @@
 #endif
 
 // For atoll (at least for NetBSD)
-#define _ISOC99_SOURCE
+#define _NETBSD_SOURCE
 
 #ifdef MSVC_USE_VLD
 #include <vld.h>
