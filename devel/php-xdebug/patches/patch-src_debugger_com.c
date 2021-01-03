$NetBSD: patch-src_debugger_com.c,v 1.2 2021/01/03 07:28:56 taca Exp $

Use standard value for second argument of setsockopt(2).

--- src/debugger/com.c.orig	2020-12-04 15:57:15.000000000 +0000
+++ src/debugger/com.c
@@ -109,7 +109,7 @@ void set_keepalive_options(int fd)
 	}
 
 	optval = 600;
-	ret = setsockopt(fd, SOL_TCP, TCP_KEEPIDLE, &optval, optlen);
+	ret = setsockopt(fd, IPPROTO_TCP, TCP_KEEPIDLE, &optval, optlen);
 	if (ret) {
 		xdebug_log_ex(XLOG_CHAN_DEBUG, XLOG_WARN, "KEEPALIVE", "Could not set TCP_KEEPIDLE to %d: %s.", optval, strerror(errno));
 		return;
@@ -117,7 +117,7 @@ void set_keepalive_options(int fd)
 
 # if defined(TCP_KEEPCNT)
 	optval = 20;
-	ret = setsockopt(fd, SOL_TCP, TCP_KEEPCNT, &optval, optlen);
+	ret = setsockopt(fd, IPPROTO_TCP, TCP_KEEPCNT, &optval, optlen);
 	if (ret) {
 		xdebug_log_ex(XLOG_CHAN_DEBUG, XLOG_WARN, "KEEPALIVE", "Could not set TCP_KEEPCNT to %d: %s.", optval, strerror(errno));
 		return;
@@ -126,7 +126,7 @@ void set_keepalive_options(int fd)
 
 # if defined(TCP_KEEPINTVL)
 	optval = 60;
-	ret = setsockopt(fd, SOL_TCP, TCP_KEEPINTVL, &optval, optlen);
+	ret = setsockopt(fd, IPPROTO_TCP, TCP_KEEPINTVL, &optval, optlen);
 	if (ret) {
 		xdebug_log_ex(XLOG_CHAN_DEBUG, XLOG_WARN, "KEEPALIVE", "Could not set TCP_KEEPINTVL to %d: %s.", optval, strerror(errno));
 		return;
