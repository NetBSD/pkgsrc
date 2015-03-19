$NetBSD: patch-sapi_fpm_fpm_fpm__sockets.c,v 1.1 2015/03/19 08:12:27 he Exp $

Treat NetBSD the same as FreeBSD wrt. tcp_info struct usage.

--- ./sapi/fpm/fpm/fpm_sockets.c.orig	2014-09-17 07:03:27.000000000 +0000
+++ ./sapi/fpm/fpm/fpm_sockets.c
@@ -405,7 +405,7 @@ int fpm_socket_get_listening_queue(int s
 		zlog(ZLOG_SYSERROR, "failed to retrieve TCP_INFO for socket");
 		return -1;
 	}
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 	if (info.__tcpi_sacked == 0) {
 		return -1;
 	}
