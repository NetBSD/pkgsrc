$NetBSD: patch-libs_indicore_indicom.c,v 1.1 2024/05/03 11:17:14 wiz Exp $

Always include ioctl.h for ioctl(), disable some code like for FreeBSD.

--- libs/indicore/indicom.c.orig	2024-05-03 10:31:04.246317754 +0000
+++ libs/indicore/indicom.c
@@ -50,9 +50,7 @@
 #include <string.h>
 #include <time.h>
 
-#ifdef __linux__
 #include <sys/ioctl.h>
-#endif
 
 #ifdef __APPLE__
 #include <sys/param.h>
@@ -793,7 +791,7 @@ int tty_connect(const char *device, int 
     case 57600:  bps = B57600;  break;
     case 115200: bps = B115200; break;
     case 230400: bps = B230400; break;
-#if !defined(__APPLE__) && !defined(__FreeBSD__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__NetBSD__)
     case 460800: bps = B460800; break;
     case 576000: bps = B576000; break;
     case 921600: bps = B921600; break;
