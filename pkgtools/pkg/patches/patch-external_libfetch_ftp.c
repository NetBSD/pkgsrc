--- external/libfetch/ftp.c.orig	2015-08-12 08:48:13 UTC
+++ external/libfetch/ftp.c
@@ -55,6 +55,10 @@
  *
  */
 
+#ifdef __NetBSD__
+#define _NETBSD_SOURCE
+#endif
+
 #include <sys/param.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
