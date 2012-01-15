$NetBSD: patch-main_asterisk.c,v 1.1.1.1 2012/01/15 18:36:21 jnemeth Exp $

--- main/asterisk.c.orig	2011-12-08 23:20:44.000000000 +0000
+++ main/asterisk.c
@@ -85,7 +85,7 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 #include <sys/sysctl.h>
 #if !defined(__OpenBSD__)
 #include <sys/vmmeter.h>
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <vm/vm_param.h>
 #endif
 #endif
