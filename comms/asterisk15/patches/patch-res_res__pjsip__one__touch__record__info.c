$NetBSD: patch-res_res__pjsip__one__touch__record__info.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_one_touch_record_info.c.orig	2018-06-20 15:23:15.924284229 +0000
+++ res/res_pjsip_one_touch_record_info.c
@@ -25,14 +25,15 @@
 
 #include "asterisk.h"
 
+#include "asterisk/features.h"
+#include "asterisk/module.h"
+#include "asterisk/features_config.h"
+
 #include <pjsip.h>
 #include <pjsip_ua.h>
 
-#include "asterisk/features.h"
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_session.h"
-#include "asterisk/module.h"
-#include "asterisk/features_config.h"
 
 static void send_response(struct ast_sip_session *session, int code, struct pjsip_rx_data *rdata)
 {
