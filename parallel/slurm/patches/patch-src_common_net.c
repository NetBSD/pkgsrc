$NetBSD: patch-src_common_net.c,v 1.1 2013/12/06 06:05:30 asau Exp $

--- src/common/net.c.orig	2013-11-04 21:19:15.000000000 +0000
+++ src/common/net.c
@@ -52,7 +52,7 @@
 #include <errno.h>
 #include <stdint.h>
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__APPLE__)
 #define	SOL_TCP		IPPROTO_TCP
 #endif
 
@@ -216,7 +216,7 @@ extern int net_set_keep_alive(int sock)
  * Removing this call might decrease the robustness of communications,
  * but will probably have no noticable effect.
  */
-#if ! defined(__FreeBSD__) || (__FreeBSD_version > 900000)
+#if (! defined(__FreeBSD__) || (__FreeBSD_version > 900000)) && ! defined(__APPLE__)
 	opt_int = keep_alive_time;
 	if (setsockopt(sock, SOL_TCP, TCP_KEEPIDLE, &opt_int, opt_len) < 0) {
 		error("Unable to set keep alive socket time: %m");
