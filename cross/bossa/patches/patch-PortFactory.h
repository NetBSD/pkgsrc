$NetBSD: patch-PortFactory.h,v 1.2 2014/02/10 20:18:04 reinoud Exp $

--- src/PortFactory.h.orig	2012-04-08 13:55:52.000000000 +0000
+++ src/PortFactory.h
@@ -45,6 +45,9 @@ typedef LinuxPortFactory PortFactory;
 #elif defined(__APPLE__)
 #include "OSXPortFactory.h"
 typedef OSXPortFactory PortFactory;
+#elif defined(__NetBSD__)
+#include "NetBSDPortFactory.h"
+typedef NetBSDPortFactory PortFactory;
 #else
 #error "Platform is not supported"
 #endif
