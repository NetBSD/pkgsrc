$NetBSD: patch-res_res__pjsip__nat.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_nat.c.orig	2018-06-20 15:19:15.829960259 +0000
+++ res/res_pjsip_nat.c
@@ -24,13 +24,14 @@
 
 #include "asterisk.h"
 
+#include "asterisk/module.h"
+#include "asterisk/acl.h"
+
 #include <pjsip.h>
 #include <pjsip_ua.h>
 
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_session.h"
-#include "asterisk/module.h"
-#include "asterisk/acl.h"
 
 static void rewrite_uri(pjsip_rx_data *rdata, pjsip_sip_uri *uri)
 {
