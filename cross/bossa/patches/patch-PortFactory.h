$NetBSD: patch-PortFactory.h,v 1.3 2015/11/08 00:02:03 dholland Exp $

Add support for NetBSD, and use it for other 4.4 derivatives as well.

--- src/PortFactory.h.orig	2012-04-08 19:55:52.000000000 +0000
+++ src/PortFactory.h
@@ -45,6 +45,10 @@ typedef LinuxPortFactory PortFactory;
 #elif defined(__APPLE__)
 #include "OSXPortFactory.h"
 typedef OSXPortFactory PortFactory;
+#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__) ||\
+      defined(__OpenBSD__) || defined(__Bitrig__)
+#include "NetBSDPortFactory.h"
+typedef NetBSDPortFactory PortFactory;
 #else
 #error "Platform is not supported"
 #endif
