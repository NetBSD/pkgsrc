$NetBSD: patch-res_res__pjsip__rfc3326.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_rfc3326.c.orig	2018-06-20 14:50:37.040036015 +0000
+++ res/res_pjsip_rfc3326.c
@@ -25,14 +25,15 @@
 
 #include "asterisk.h"
 
+#include "asterisk/module.h"
+#include "asterisk/causes.h"
+#include "asterisk/threadpool.h"
+
 #include <pjsip.h>
 #include <pjsip_ua.h>
 
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_session.h"
-#include "asterisk/module.h"
-#include "asterisk/causes.h"
-#include "asterisk/threadpool.h"
 
 static void rfc3326_use_reason_header(struct ast_sip_session *session, struct pjsip_rx_data *rdata)
 {
