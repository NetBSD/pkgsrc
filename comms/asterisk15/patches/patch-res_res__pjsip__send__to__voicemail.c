$NetBSD: patch-res_res__pjsip__send__to__voicemail.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_send_to_voicemail.c.orig	2018-06-20 14:58:59.976213530 +0000
+++ res/res_pjsip_send_to_voicemail.c
@@ -33,13 +33,14 @@
 
 #include "asterisk.h"
 
+#include "asterisk/pbx.h"
+#include "asterisk/module.h"
+
 #include <pjsip.h>
 #include <pjsip_ua.h>
 
-#include "asterisk/pbx.h"
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_session.h"
-#include "asterisk/module.h"
 
 #define DATASTORE_NAME "call_feature_send_to_vm_datastore"
 
