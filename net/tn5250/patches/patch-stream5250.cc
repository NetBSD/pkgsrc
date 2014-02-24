$NetBSD: patch-stream5250.cc,v 1.1 2014/02/24 13:11:53 wiedi Exp $

need filio.h for FIONBIO on SunOS
--- stream5250.cc.orig	1999-04-05 16:25:45.000000000 +0000
+++ stream5250.cc
@@ -27,6 +27,9 @@
 #include <sys/types.h>
 #ifndef WIN32
 #include <sys/time.h>
+#if defined(__sun)
+#include <sys/filio.h>
+#endif
 #include <sys/ioctl.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
