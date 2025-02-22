$NetBSD: patch-src_smtpd_smtpd.c,v 1.4 2025/02/22 16:00:18 taca Exp $

Add blocklist(3) support.

--- src/smtpd/smtpd.c.orig	2025-02-05 22:04:14.000000000 +0000
+++ src/smtpd/smtpd.c
@@ -1349,6 +1349,8 @@
 #include <smtpd_milter.h>
 #include <smtpd_expand.h>
 
+#include "pfilter.h"
+
  /*
   * Tunable parameters. Make sure that there is some bound on the length of
   * an SMTP command, so that the mail system stays in control even when a
@@ -6154,6 +6156,10 @@ static void smtpd_proto(SMTPD_STATE *sta
 	    msg_info("%s: %s after %s from %s",
 		     queue_id_or_noqueue,
 		     state->reason, state->where, state->namaddr);
+#if defined(HAVE_BLOCKLIST) || defined(HAVE_BLACKLIST)
+	    if (strcmp(state->where, SMTPD_CMD_AUTH) == 0)
+		    pfilter_notify(1, vstream_fileno(state->client));
+#endif
 	}
     }
 
