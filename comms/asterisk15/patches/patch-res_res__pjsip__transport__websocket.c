$NetBSD: patch-res_res__pjsip__transport__websocket.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_transport_websocket.c.orig	2018-06-20 14:55:54.355115874 +0000
+++ res/res_pjsip_transport_websocket.c
@@ -29,14 +29,15 @@
 
 #include "asterisk.h"
 
+#include "asterisk/module.h"
+#include "asterisk/http_websocket.h"
+#include "asterisk/taskprocessor.h"
+
 #include <pjsip.h>
 #include <pjsip_ua.h>
 
-#include "asterisk/module.h"
-#include "asterisk/http_websocket.h"
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_session.h"
-#include "asterisk/taskprocessor.h"
 
 static int transport_type_wss;
 static int transport_type_wss_ipv6;
