$NetBSD: patch-PortFactory.h,v 1.1 2014/01/14 15:36:59 reinoud Exp $

Add NetBSDPortFactory class

--- /usr/tmp/pkgsrc-aspire/comms/bossa/work/b-o-s-s-a-code-05bfcc39bc0453c3028b1161175b95a81af7a901/src/PortFactory.h.orig	2012-04-08 13:55:52.000000000 +0000
+++ /usr/tmp/pkgsrc-aspire/comms/bossa/work/b-o-s-s-a-code-05bfcc39bc0453c3028b1161175b95a81af7a901/src/PortFactory.h
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
