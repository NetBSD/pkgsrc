$NetBSD: patch-res_res__pjsip__empty__info.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_empty_info.c.orig	2018-06-20 15:17:23.874357861 +0000
+++ res/res_pjsip_empty_info.c
@@ -25,12 +25,13 @@
 
 #include "asterisk.h"
 
+#include "asterisk/module.h"
+
 #include <pjsip.h>
 #include <pjsip_ua.h>
 
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_session.h"
-#include "asterisk/module.h"
 
 static void send_response(struct ast_sip_session *session,
 		struct pjsip_rx_data *rdata, int code)
