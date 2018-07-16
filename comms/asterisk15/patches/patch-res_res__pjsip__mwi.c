$NetBSD: patch-res_res__pjsip__mwi.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_mwi.c.orig	2018-06-20 15:14:36.457639759 +0000
+++ res/res_pjsip_mwi.c
@@ -25,13 +25,6 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-#include <pjsip_simple.h>
-#include <pjlib.h>
-
-#include "asterisk/res_pjsip.h"
-#include "asterisk/res_pjsip_pubsub.h"
-#include "asterisk/res_pjsip_body_generator_types.h"
 #include "asterisk/module.h"
 #include "asterisk/logger.h"
 #include "asterisk/astobj2.h"
@@ -40,6 +33,14 @@
 #include "asterisk/stasis.h"
 #include "asterisk/app.h"
 
+#include <pjsip.h>
+#include <pjsip_simple.h>
+#include <pjlib.h>
+
+#include "asterisk/res_pjsip.h"
+#include "asterisk/res_pjsip_pubsub.h"
+#include "asterisk/res_pjsip_body_generator_types.h"
+
 struct mwi_subscription;
 static struct ao2_container *unsolicited_mwi;
 
