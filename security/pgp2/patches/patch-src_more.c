$NetBSD: patch-src_more.c,v 1.1 2025/10/10 19:11:59 mrg Exp $

Also include sys/ioctl.h on NetBSD.


--- more.c.orig	1996-01-06 11:54:04.000000000 -0800
+++ more.c	2025-10-10 12:07:52.897573874 -0700
@@ -107,7 +107,7 @@ extern int tgetent(), tgetnum();
 #endif				/* SVR2 */
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/ioctl.h>          /* for ioctl() prototype too */
 #else
 #ifndef SVR2
