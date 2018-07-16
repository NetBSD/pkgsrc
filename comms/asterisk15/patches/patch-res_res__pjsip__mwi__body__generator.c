$NetBSD: patch-res_res__pjsip__mwi__body__generator.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_mwi_body_generator.c.orig	2018-06-20 15:23:44.066022439 +0000
+++ res/res_pjsip_mwi_body_generator.c
@@ -25,6 +25,9 @@
 
 #include "asterisk.h"
 
+#include "asterisk/module.h"
+#include "asterisk/strings.h"
+
 #include <pjsip.h>
 #include <pjsip_simple.h>
 #include <pjlib.h>
@@ -32,8 +35,6 @@
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_pubsub.h"
 #include "asterisk/res_pjsip_body_generator_types.h"
-#include "asterisk/module.h"
-#include "asterisk/strings.h"
 
 #define MWI_TYPE "application"
 #define MWI_SUBTYPE "simple-message-summary"
