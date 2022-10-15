$NetBSD: patch-src_smtpd_smtpd.c,v 1.3 2022/10/15 20:34:57 triaxx Exp $

Add blocklist(3) support.

--- src/smtpd/smtpd.c.orig	2021-07-24 21:43:57.000000000 +0000
+++ src/smtpd/smtpd.c
@@ -1292,6 +1292,8 @@
 #include <smtpd_milter.h>
 #include <smtpd_expand.h>
 
+#include "pfilter.h"
+
  /*
   * Tunable parameters. Make sure that there is some bound on the length of
   * an SMTP command, so that the mail system stays in control even when a
@@ -5865,6 +5867,10 @@ static void smtpd_proto(SMTPD_STATE *sta
 		   || strcmp(state->reason, REASON_LOST_CONNECTION)) {
 	    msg_info("%s after %s from %s",
 		     state->reason, state->where, state->namaddr);
+#if defined(HAVE_BLOCKLIST) || defined(HAVE_BLACKLIST)
+	    if (strcmp(state->where, SMTPD_CMD_AUTH) == 0)
+		pfilter_notify(1, vstream_fileno(state->client));
+#endif
 	}
     }
 
