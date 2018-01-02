$NetBSD: patch-src_old-stats_mail-stats.h,v 1.1 2018/01/02 15:52:44 fhajny Exp $

Fix build under NetBSD (at least amd64 7.0_BETA).

--- src/old-stats/mail-stats.h.orig	2016-12-03 17:13:21.000000000 +0000
+++ src/old-stats/mail-stats.h
@@ -9,6 +9,10 @@
 
 struct stats_send_ctx;
 
+#ifdef __NetBSD__
+#include <sys/time.h>
+#endif
+
 struct mail_command {
 	struct mail_command *stable_prev, *stable_next;
 	struct mail_command *session_prev, *session_next;
