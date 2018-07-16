$NetBSD: patch-res_res__pjsip__xpidf__body__generator.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_xpidf_body_generator.c.orig	2018-06-20 14:57:12.605637881 +0000
+++ res/res_pjsip_xpidf_body_generator.c
@@ -26,11 +26,12 @@
 
 #include "asterisk.h"
 
+#include "asterisk/module.h"
+
 #include <pjsip.h>
 #include <pjsip_simple.h>
 #include <pjlib.h>
 
-#include "asterisk/module.h"
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_pubsub.h"
 #include "asterisk/res_pjsip_presence_xml.h"
