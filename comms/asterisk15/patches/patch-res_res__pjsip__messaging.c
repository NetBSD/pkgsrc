$NetBSD: patch-res_res__pjsip__messaging.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_messaging.c.orig	2018-06-20 14:44:43.652384305 +0000
+++ res/res_pjsip_messaging.c
@@ -35,14 +35,14 @@
  ***/
 #include "asterisk.h"
 
-#include "pjsua-lib/pjsua.h"
-
 #include "asterisk/message.h"
 #include "asterisk/module.h"
 #include "asterisk/pbx.h"
+#include "asterisk/taskprocessor.h"
+
+#include "pjsua-lib/pjsua.h"
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_session.h"
-#include "asterisk/taskprocessor.h"
 
 const pjsip_method pjsip_message_method = {PJSIP_OTHER_METHOD, {"MESSAGE", 7} };
 
