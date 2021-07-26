$NetBSD: patch-src_smtpd_smtpd.c,v 1.1 2021/07/26 15:38:10 taca Exp $

Add blocklist(3) support.

--- src/smtpd/smtpd.c.orig	2021-07-24 21:43:57.000000000 +0000
+++ src/smtpd/smtpd.c
@@ -1263,6 +1263,8 @@
 #include <smtpd_milter.h>
 #include <smtpd_expand.h>
 
+#include "pfilter.h"
+
  /*
   * Tunable parameters. Make sure that there is some bound on the length of
   * an SMTP command, so that the mail system stays in control even when a
@@ -5804,6 +5806,8 @@ static void smtpd_proto(SMTPD_STATE *sta
 		   || strcmp(state->reason, REASON_LOST_CONNECTION)) {
 	    msg_info("%s after %s from %s",
 		     state->reason, state->where, state->namaddr);
+	    if (strcmp(state->where, SMTPD_CMD_AUTH) == 0)
+		pfilter_notify(1, vstream_fileno(state->client));
 	}
     }
 
