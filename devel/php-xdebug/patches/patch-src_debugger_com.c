$NetBSD: patch-src_debugger_com.c,v 1.1 2020/09/19 13:35:16 taca Exp $

Use standard value for second argument of setsockopt(2).

--- src/debugger/com.c.orig	2020-09-16 14:14:16.000000000 +0000
+++ src/debugger/com.c
@@ -106,19 +106,19 @@ void set_keepalive_options(int fd)
 	}
 
 	optval = 600;
-	ret = setsockopt(fd, SOL_TCP, TCP_KEEPIDLE, &optval, optlen);
+	ret = setsockopt(fd, IPPROTO_TCP, TCP_KEEPIDLE, &optval, optlen);
 	if (ret) {
 		return;
 	}
 
 	optval = 20;
-	ret = setsockopt(fd, SOL_TCP, TCP_KEEPCNT, &optval, optlen);
+	ret = setsockopt(fd, IPPROTO_TCP, TCP_KEEPCNT, &optval, optlen);
 	if (ret) {
 		return;
 	}
 
 	optval = 60;
-	ret = setsockopt(fd, SOL_TCP, TCP_KEEPINTVL, &optval, optlen);
+	ret = setsockopt(fd, IPPROTO_TCP, TCP_KEEPINTVL, &optval, optlen);
 	if (ret) {
 		return;
 	}
