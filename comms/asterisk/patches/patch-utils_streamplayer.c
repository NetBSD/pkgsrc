$NetBSD: patch-utils_streamplayer.c,v 1.1 2012/12/11 08:22:49 jnemeth Exp $

--- utils/streamplayer.c.orig	2011-07-14 20:28:54.000000000 +0000
+++ utils/streamplayer.c
@@ -53,7 +53,7 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/socket.h>
-#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__Darwin__) || defined(__CYGWIN__)
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__Darwin__) || defined(__CYGWIN__) || defined(__DragonFly__)
 #include <netinet/in.h>
 #endif
 #include <sys/time.h>
