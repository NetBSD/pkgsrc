$NetBSD: patch-res_res__hep__pjsip.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- res/res_hep_pjsip.c.orig	2018-06-20 15:24:25.999288749 +0000
+++ res/res_hep_pjsip.c
@@ -34,6 +34,9 @@
 
 #include "asterisk.h"
 
+#include "asterisk/module.h"
+#include "asterisk/netsock2.h"
+
 #include <pjsip.h>
 #include <pjsip_ua.h>
 #include <pjlib.h>
@@ -41,8 +44,6 @@
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_session.h"
 #include "asterisk/res_hep.h"
-#include "asterisk/module.h"
-#include "asterisk/netsock2.h"
 
 static char *assign_uuid(const pj_str_t *call_id, const pj_str_t *local_tag, const pj_str_t *remote_tag)
 {
