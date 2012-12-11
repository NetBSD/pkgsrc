$NetBSD: patch-main_asterisk.c,v 1.1 2012/12/11 08:22:49 jnemeth Exp $

--- main/asterisk.c.orig	2012-09-11 21:04:36.000000000 +0000
+++ main/asterisk.c
@@ -89,7 +89,7 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 #include <sys/sysctl.h>
 #if !defined(__OpenBSD__)
 #include <sys/vmmeter.h>
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <vm/vm_param.h>
 #endif
 #endif
