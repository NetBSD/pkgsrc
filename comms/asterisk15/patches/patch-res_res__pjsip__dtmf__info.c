$NetBSD: patch-res_res__pjsip__dtmf__info.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_dtmf_info.c.orig	2018-06-20 15:18:23.473675677 +0000
+++ res/res_pjsip_dtmf_info.c
@@ -25,12 +25,13 @@
 
 #include "asterisk.h"
 
+#include "asterisk/module.h"
+
 #include <pjsip.h>
 #include <pjsip_ua.h>
 
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_session.h"
-#include "asterisk/module.h"
 
 static int is_media_type(pjsip_rx_data *rdata, char *subtype)
 {
