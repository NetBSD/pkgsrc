$NetBSD: patch-lib_rtp_net__udp.c,v 1.1 2017/05/06 18:12:00 maya Exp $

No point in collecting retlen if we're just going to ignore it.

--- lib/rtp/net_udp.c.orig	2007-09-18 20:52:01.000000000 +0000
+++ lib/rtp/net_udp.c
@@ -163,9 +163,8 @@ socket_error(const char *msg, ...)
 	va_end(ap);
 	rtp_message(LOG_ALERT, "ERROR: %s, (%d - %s)\n", buffer, e, ws_errs[i].errname);
 #else
-	uint32_t retlen;
 	va_start(ap, msg);
-	retlen = vsnprintf(buffer, blen, msg, ap);
+	(void)vsnprintf(buffer, blen, msg, ap);
 	va_end(ap);
 	rtp_message(LOG_ALERT, "%s:%s", buffer, strerror(errno));
 #endif
