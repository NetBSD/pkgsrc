$NetBSD: patch-forkpty.c,v 1.1 2026/11/18 02:18:30 ktnb Exp $

Bypass linux-specific ioctl(3) calls

--- forkpty.c.orig	2026-11-17 21:55:18.545444024 +0000
+++ forkpty.c
@@ -20,7 +20,9 @@
 #include <stdlib.h>
 #include <sys/types.h>
 #include <sys/termios.h>
+#ifndef __NetBSD__
 #include <stropts.h>
+#endif
 
 #define DEV_PTMX "/dev/ptmx"
 
@@ -77,6 +79,12 @@ int open_slave(char *name)
 int open_slave(char *name)
 {
 	int fd;
+#ifdef __NetBSD__
+	fd = open(name, O_RDWR | O_NOCTTY);
+	if (fd < 0)
+		return EPTMX_OPEN;
+	return fd;
+#else
 	int status;
 
 	fd = open(name, O_RDWR);
@@ -112,6 +120,7 @@ int open_slave(char *name)
 	}
 
 	return fd;
+#endif
 }
 
 
