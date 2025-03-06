$NetBSD: patch-src_xpdev_sockwrap.h,v 1.1 2025/03/06 04:33:36 vins Exp $

Define FIONBIO on illumos. 

--- src/xpdev/sockwrap.h.orig	2025-03-05 22:05:50.777295821 +0000
+++ src/xpdev/sockwrap.h
@@ -71,9 +71,11 @@ typedef int* socket_ioctl_ptr_t;
 #include <netinet/tcp.h>	/* TCP_NODELAY */
 #include <unistd.h>			/* close */
 #include <poll.h>
-#if defined(__solaris__)
+#if defined(__sun)
 	#include <sys/filio.h>  /* FIONBIO */
-	#define INADDR_NONE -1L
+#ifndef INADDR_NONE
+#define INADDR_NONE -1L
+#endif
 #else
 	#include <sys/ioctl.h>	/* FIONBIO */
 #endif
