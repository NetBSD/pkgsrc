$NetBSD: patch-res_res__pjsip__pidf__eyebeam__body__supplement.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_pidf_eyebeam_body_supplement.c.orig	2018-06-20 15:13:48.837303343 +0000
+++ res/res_pjsip_pidf_eyebeam_body_supplement.c
@@ -25,11 +25,12 @@
 
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
