$NetBSD: patch-src_chart1.cpp,v 1.2 2015/01/22 12:34:15 bouyer Exp $

Adapt for tty devices on NetBSD
Reported in FS#1403

--- src/chart1.cpp.orig	2014-05-26 21:26:36.000000000 +0200
+++ src/chart1.cpp	2014-05-26 21:30:22.000000000 +0200
@@ -8032,7 +8032,9 @@
 
 #include <termios.h>
 #include <sys/ioctl.h>
+#ifdef __linux__
 #include <linux/serial.h>
+#endif
 
 #endif
 
@@ -8098,6 +8100,15 @@
 
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
 
@@ -8114,6 +8125,7 @@
     }
 
     return ret;
+#endif /* !NetBSD */
 }
 
 
@@ -8154,11 +8166,13 @@
 
 //        We try to add a few more, arbitrarily, for those systems that have fixed, traditional COM ports
 
+#ifdef __linux__
     if( isTTYreal("/dev/ttyS0") )
         preturn->Add( _T("/dev/ttyS0") );
 
     if( isTTYreal("/dev/ttyS1") )
         preturn->Add( _T("/dev/ttyS1") );
+#endif /* linux */
 
 
 #endif
