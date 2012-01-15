$NetBSD: patch-channels_chan__oss.c,v 1.1.1.1 2012/01/15 18:36:21 jnemeth Exp $

--- channels/chan_oss.c.orig	2011-09-09 16:27:01.000000000 +0000
+++ channels/chan_oss.c
@@ -48,7 +48,7 @@ ASTERISK_FILE_VERSION(__FILE__, "$Revisi
 
 #ifdef __linux
 #include <linux/soundcard.h>
-#elif defined(__FreeBSD__) || defined(__CYGWIN__) || defined(__GLIBC__)
+#elif defined(__FreeBSD__) || defined(__CYGWIN__) || defined(__DragonFly__) || defined(__GLIBC__)
 #include <sys/soundcard.h>
 #else
 #include <soundcard.h>
