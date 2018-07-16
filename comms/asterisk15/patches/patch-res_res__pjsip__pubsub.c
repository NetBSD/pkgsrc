$NetBSD: patch-res_res__pjsip__pubsub.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_pubsub.c.orig	2018-06-20 14:55:07.570481514 +0000
+++ res/res_pjsip_pubsub.c
@@ -27,12 +27,7 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-#include <pjsip_simple.h>
-#include <pjlib.h>
-
 #include "asterisk/app.h"
-#include "asterisk/res_pjsip_pubsub.h"
 #include "asterisk/module.h"
 #include "asterisk/linkedlists.h"
 #include "asterisk/astobj2.h"
@@ -40,11 +35,17 @@
 #include "asterisk/uuid.h"
 #include "asterisk/taskprocessor.h"
 #include "asterisk/sched.h"
-#include "asterisk/res_pjsip.h"
 #include "asterisk/callerid.h"
 #include "asterisk/manager.h"
 #include "asterisk/cli.h"
 #include "asterisk/test.h"
+
+#include <pjsip.h>
+#include <pjsip_simple.h>
+#include <pjlib.h>
+
+#include "asterisk/res_pjsip_pubsub.h"
+#include "asterisk/res_pjsip.h"
 #include "res_pjsip/include/res_pjsip_private.h"
 #include "asterisk/res_pjsip_presence_xml.h"
 
