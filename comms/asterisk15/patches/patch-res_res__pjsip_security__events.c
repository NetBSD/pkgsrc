$NetBSD: patch-res_res__pjsip_security__events.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip/security_events.c.orig	2018-06-20 15:13:16.454003414 +0000
+++ res/res_pjsip/security_events.c
@@ -26,10 +26,11 @@
 
 #include "asterisk.h"
 
+#include "asterisk/security_events.h"
+
 #include <pjsip.h>
 
 #include "asterisk/res_pjsip.h"
-#include "asterisk/security_events.h"
 
 static enum ast_transport security_event_get_transport(pjsip_rx_data *rdata)
 {
