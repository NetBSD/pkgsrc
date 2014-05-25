$NetBSD: patch-src_chart1.cpp,v 1.1 2014/05/25 18:26:57 bouyer Exp $

Adapt for tty devices on NetBSD

--- src/chart1.cpp.orig	2014-05-23 15:58:32.000000000 +0200
+++ src/chart1.cpp	2014-05-23 16:03:10.000000000 +0200
@@ -7305,7 +7305,9 @@
 
 #include <termios.h>
 #include <sys/ioctl.h>
+#ifdef __linux__
 #include <linux/serial.h>
+#endif
 
 #endif
 
@@ -7371,6 +7373,15 @@
 
 int isTTYreal(const char *dev)
 {
+#ifdef __NetBSD__
+    if (strncmp("/dev/tty0", dev, 9) == 0)
+	return 1;
+    if (strncmp("/dev/ttyU", dev, 9) == 0)
+	return 1;
+    if (strcmp("/dev/gps", dev) == 0)
+	return 1;
+    return 0;
+#else /* !NetBSD */
     struct serial_struct serinfo;
     int ret = 0;
 
@@ -7387,6 +7398,7 @@
     }
 
     return ret;
+#endif /* !NetBSD */
 }
 
 
@@ -7427,11 +7439,13 @@
 
 //        We try to add a few more, arbitrarily, for those systems that have fixed, traditional COM ports
 
+#ifdef __linux__
     if( isTTYreal("/dev/ttyS0") )
         preturn->Add( _T("/dev/ttyS0") );
 
     if( isTTYreal("/dev/ttyS1") )
         preturn->Add( _T("/dev/ttyS1") );
+#endif /* linux */
 
 
 #endif
