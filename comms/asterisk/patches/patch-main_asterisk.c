$NetBSD: patch-main_asterisk.c,v 1.2 2015/05/19 07:52:14 jnemeth Exp $

--- main/asterisk.c.orig	2015-03-22 20:32:17.000000000 +0000
+++ main/asterisk.c
@@ -88,7 +88,7 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #include <sys/vmmeter.h>
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <vm/vm_param.h>
 #endif
 #if defined(HAVE_SWAPCTL)
