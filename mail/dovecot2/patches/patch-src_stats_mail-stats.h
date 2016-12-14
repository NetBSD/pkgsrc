$NetBSD: patch-src_stats_mail-stats.h,v 1.2 2016/12/14 15:48:09 adam Exp $

Fix build under NetBSD (at least amd64 7.0_BETA).

--- src/stats/mail-stats.h.orig	2016-12-03 17:13:21.000000000 +0000
+++ src/stats/mail-stats.h
@@ -9,6 +9,10 @@
 
 struct stats_send_ctx;
 
+#ifdef __NetBSD__
+#include <sys/time.h>
+#endif
+
 struct mail_command {
 	struct mail_command *stable_prev, *stable_next;
 	struct mail_command *session_prev, *session_next;
