$NetBSD: patch-src_debugger_com.c,v 1.3 2021/02/02 15:03:36 taca Exp $

Use standard value for second argument of setsockopt(2).

--- src/debugger/com.c.orig	2021-01-04 17:17:01.000000000 +0000
+++ src/debugger/com.c
@@ -110,7 +110,7 @@ void set_keepalive_options(int fd)
 
 # if defined(TCP_KEEPIDLE)
 	optval = 600;
-	ret = setsockopt(fd, SOL_TCP, TCP_KEEPIDLE, &optval, optlen);
+	ret = setsockopt(fd, IPPROTO_TCP, TCP_KEEPIDLE, &optval, optlen);
 	if (ret) {
 		xdebug_log_ex(XLOG_CHAN_DEBUG, XLOG_WARN, "KEEPALIVE", "Could not set TCP_KEEPIDLE to %d: %s.", optval, strerror(errno));
 		return;
@@ -119,7 +119,7 @@ void set_keepalive_options(int fd)
 
 # if defined(TCP_KEEPCNT)
 	optval = 20;
-	ret = setsockopt(fd, SOL_TCP, TCP_KEEPCNT, &optval, optlen);
+	ret = setsockopt(fd, IPPROTO_TCP, TCP_KEEPCNT, &optval, optlen);
 	if (ret) {
 		xdebug_log_ex(XLOG_CHAN_DEBUG, XLOG_WARN, "KEEPALIVE", "Could not set TCP_KEEPCNT to %d: %s.", optval, strerror(errno));
 		return;
@@ -128,7 +128,7 @@ void set_keepalive_options(int fd)
 
 # if defined(TCP_KEEPINTVL)
 	optval = 60;
-	ret = setsockopt(fd, SOL_TCP, TCP_KEEPINTVL, &optval, optlen);
+	ret = setsockopt(fd, IPPROTO_TCP, TCP_KEEPINTVL, &optval, optlen);
 	if (ret) {
 		xdebug_log_ex(XLOG_CHAN_DEBUG, XLOG_WARN, "KEEPALIVE", "Could not set TCP_KEEPINTVL to %d: %s.", optval, strerror(errno));
 		return;
