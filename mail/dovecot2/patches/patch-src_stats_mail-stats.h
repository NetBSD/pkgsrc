$NetBSD: patch-src_stats_mail-stats.h,v 1.1 2015/03/15 09:19:24 tron Exp $

Fix build under NetBSD (at least amd64 7.0_BETA).

--- src/stats/mail-stats.h.orig	2015-03-05 15:19:20.000000000 +0000
+++ src/stats/mail-stats.h	2015-03-15 09:13:07.000000000 +0000
@@ -5,6 +5,10 @@
 #include "guid.h"
 #include "stats.h"
 
+#ifdef __NetBSD__
+#include <sys/time.h>
+#endif
+
 struct mail_command {
 	struct mail_command *stable_prev, *stable_next;
 	struct mail_command *session_prev, *session_next;
