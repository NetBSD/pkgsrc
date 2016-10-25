$NetBSD: patch-main_asterisk.c,v 1.1.1.1 2016/10/25 08:17:08 jnemeth Exp $

--- main/asterisk.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ main/asterisk.c
@@ -172,7 +172,7 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #include <sys/vmmeter.h>
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <vm/vm_param.h>
 #endif
 #if defined(HAVE_SWAPCTL)
