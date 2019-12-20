$NetBSD: patch-unix_plugins_SerialPlugin_sqUnixSerial.c,v 1.1 2019/12/20 00:01:37 joerg Exp $

--- unix/plugins/SerialPlugin/sqUnixSerial.c.orig	2019-12-19 23:17:52.826888467 +0000
+++ unix/plugins/SerialPlugin/sqUnixSerial.c
@@ -16,6 +16,11 @@
 #include <termios.h>
 #include <errno.h>
 
+#ifdef __NetBSD__
+#define B576000		576000U
+#define B1152000	1152000U
+#endif
+
 /*** Module variables ***/
 
 #define PORT_NAME_SIZE 64
