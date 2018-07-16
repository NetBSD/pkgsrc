$NetBSD: patch-res_res__pjsip__pidf__digium__body__supplement.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_pidf_digium_body_supplement.c.orig	2018-06-20 15:16:30.009948356 +0000
+++ res/res_pjsip_pidf_digium_body_supplement.c
@@ -25,12 +25,13 @@
 
 #include "asterisk.h"
 
+#include "asterisk/module.h"
+#include "asterisk/presencestate.h"
+
 #include <pjsip.h>
 #include <pjsip_simple.h>
 #include <pjlib.h>
 
-#include "asterisk/module.h"
-#include "asterisk/presencestate.h"
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_pubsub.h"
 #include "asterisk/res_pjsip_presence_xml.h"
