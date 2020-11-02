$NetBSD: patch-src_player.c,v 1.2 2020/11/02 20:17:15 nia Exp $

Pointlessly checking for FreeBSD here.

https://github.com/ejurgensen/forked-daapd/pull/1114

--- src/player.c.orig	2020-07-23 06:49:22.000000000 +0000
+++ src/player.c
@@ -65,7 +65,7 @@
 
 #ifdef HAVE_TIMERFD
 # include <sys/timerfd.h>
-#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#else
 # include <signal.h>
 #endif
 
