$NetBSD: patch-new__curse.c,v 1.1 2013/07/18 12:07:24 joerg Exp $

--- new_curse.c.orig	2013-07-17 14:38:02.000000000 +0000
+++ new_curse.c
@@ -83,6 +83,7 @@ char * new_curse_name= "@(#) new_curse.c
 #ifdef HAS_SYS_IOCTL
 #include <sys/ioctl.h>
 #endif
+#include <termios.h>
 
 
 WINDOW *curscr;
