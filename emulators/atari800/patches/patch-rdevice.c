$NetBSD: patch-rdevice.c,v 1.1 2012/08/26 19:42:09 marino Exp $

Add i386 DragonFly support (Same as FreeBSD but on its own line)

--- rdevice.c.orig	2011-04-28 10:49:39.000000000 +0000
+++ rdevice.c
@@ -819,6 +819,8 @@ static void open_connection(char * addre
 #define TTY_DEV_NAME "/dev/tty00"   /* NetBSD/x86 */
 #elif defined (__FreeBSD__) && defined(__i386__)
 #define TTY_DEV_NAME "/dev/ttyd1"   /* FreeBSD/x86 */
+#elif defined (__DragonFly__) && defined(__i386__)
+#define TTY_DEV_NAME "/dev/ttyd1"   /* DragonFly/x86 */
 #elif defined (__sun__)
 #define TTY_DEV_NAME "/dev/ttya"    /* Solaris */
 #else
