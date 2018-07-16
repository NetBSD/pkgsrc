$NetBSD: patch-res_res__pjsip__endpoint__identifier__ip.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_endpoint_identifier_ip.c.orig	2018-06-20 14:53:35.046125088 +0000
+++ res/res_pjsip_endpoint_identifier_ip.c
@@ -24,13 +24,14 @@
 
 #include "asterisk.h"
 
+#include "asterisk/module.h"
+#include "asterisk/acl.h"
+#include "asterisk/manager.h"
+
 #include <pjsip.h>
 
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_cli.h"
-#include "asterisk/module.h"
-#include "asterisk/acl.h"
-#include "asterisk/manager.h"
 #include "res_pjsip/include/res_pjsip_private.h"
 
 /*** DOCUMENTATION
