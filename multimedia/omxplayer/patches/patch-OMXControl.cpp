$NetBSD: patch-OMXControl.cpp,v 1.1 2015/01/18 23:09:25 jmcneill Exp $

--- OMXControl.cpp.orig	2015-01-12 15:10:50.000000000 +0000
+++ OMXControl.cpp
@@ -2,7 +2,9 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <sys/mman.h>
+#if defined(__linux__)
 #include <linux/fb.h>
+#endif
 #include <string.h>
 #include <dbus/dbus.h>
 
