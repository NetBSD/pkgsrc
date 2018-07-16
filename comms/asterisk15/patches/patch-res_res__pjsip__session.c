$NetBSD: patch-res_res__pjsip__session.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_session.c.orig	2018-06-20 15:26:23.023816148 +0000
+++ res/res_pjsip_session.c
@@ -24,17 +24,10 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-#include <pjsip_ua.h>
-#include <pjlib.h>
-
-#include "asterisk/res_pjsip.h"
-#include "asterisk/res_pjsip_session.h"
 #include "asterisk/callerid.h"
 #include "asterisk/datastore.h"
 #include "asterisk/module.h"
 #include "asterisk/logger.h"
-#include "asterisk/res_pjsip.h"
 #include "asterisk/astobj2.h"
 #include "asterisk/lock.h"
 #include "asterisk/uuid.h"
@@ -49,6 +42,14 @@
 #include "asterisk/test.h"
 #include "asterisk/stream.h"
 
+#include <pjsip.h>
+#include <pjsip_ua.h>
+#include <pjlib.h>
+
+#include "asterisk/res_pjsip.h"
+#include "asterisk/res_pjsip_session.h"
+#include "asterisk/res_pjsip.h"
+
 #define SDP_HANDLER_BUCKETS 11
 
 #define MOD_DATA_ON_RESPONSE "on_response"
