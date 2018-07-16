$NetBSD: patch-res_res__pjsip__exten__state.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_exten_state.c.orig	2018-06-20 15:27:23.695134703 +0000
+++ res/res_pjsip_exten_state.c
@@ -28,6 +28,13 @@
 
 #include <regex.h>
 
+#include "asterisk/module.h"
+#include "asterisk/logger.h"
+#include "asterisk/astobj2.h"
+#include "asterisk/sorcery.h"
+#include "asterisk/app.h"
+#include "asterisk/taskprocessor.h"
+
 #include <pjsip.h>
 #include <pjsip_simple.h>
 #include <pjlib.h>
@@ -36,12 +43,6 @@
 #include "asterisk/res_pjsip_outbound_publish.h"
 #include "asterisk/res_pjsip_pubsub.h"
 #include "asterisk/res_pjsip_body_generator_types.h"
-#include "asterisk/module.h"
-#include "asterisk/logger.h"
-#include "asterisk/astobj2.h"
-#include "asterisk/sorcery.h"
-#include "asterisk/app.h"
-#include "asterisk/taskprocessor.h"
 
 #define BODY_SIZE 1024
 #define EVENT_TYPE_SIZE 50
