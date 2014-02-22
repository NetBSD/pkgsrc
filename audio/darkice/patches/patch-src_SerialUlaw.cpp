$NetBSD: patch-src_SerialUlaw.cpp,v 1.1 2014/02/22 14:51:03 wiedi Exp $

cfmakeraw is not portable to SunOS
--- src/SerialUlaw.cpp.orig	2013-07-15 05:50:42.000000000 +0000
+++ src/SerialUlaw.cpp
@@ -232,7 +232,15 @@ SerialUlaw :: open ( void )
     }
 
     cfsetispeed(&ts, B115200);
+#if defined(__sun)
+    ts.c_iflag &= ~(IMAXBEL|IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);
+    ts.c_oflag &= ~OPOST;
+    ts.c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
+    ts.c_cflag &= ~(CSIZE|PARENB);
+    ts.c_cflag |= CS8;
+#else
     cfmakeraw(&ts);
+#endif
     ts.c_cflag |= CLOCAL;
     if(tcsetattr(fileDescriptor, TCSANOW, &ts) < 0) {
         close();
