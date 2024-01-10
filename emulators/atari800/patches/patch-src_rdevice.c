$NetBSD: patch-src_rdevice.c,v 1.2 2024/01/10 17:57:15 adam Exp $

These are not architecture-specific.

--- src/rdevice.c.orig	2023-12-29 09:23:46.000000000 +0000
+++ src/rdevice.c
@@ -819,9 +819,9 @@ static void open_connection(char * addre
 #if defined(R_SERIAL) && !defined(DREAMCAST)
 #ifdef __linux__
 #define TTY_DEV_NAME "/dev/ttyS0"   /* Linux */
-#elif defined (__NetBSD__) && (defined(__i386__) || defined(__amd64__))
+#elif defined (__NetBSD__)
 #define TTY_DEV_NAME "/dev/tty00"   /* NetBSD/x86 */
-#elif defined (__FreeBSD__) && (defined(__i386__) || defined(__amd64__))
+#elif defined (__FreeBSD__)
 #define TTY_DEV_NAME "/dev/ttyd1"   /* FreeBSD/x86 */
 #elif defined (__sun__)
 #define TTY_DEV_NAME "/dev/ttya"    /* Solaris */
