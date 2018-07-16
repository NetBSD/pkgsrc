$NetBSD: patch-res_res__pjsip_config__domain__aliases.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip/config_domain_aliases.c.orig	2018-06-20 15:08:56.215815643 +0000
+++ res/res_pjsip/config_domain_aliases.c
@@ -18,12 +18,13 @@
 
 #include "asterisk.h"
 
+#include "asterisk/logger.h"
+#include "asterisk/sorcery.h"
+
 #include "pjsip.h"
 #include "pjlib.h"
 #include "asterisk/res_pjsip.h"
 #include "include/res_pjsip_private.h"
-#include "asterisk/logger.h"
-#include "asterisk/sorcery.h"
 
 static void domain_alias_destroy(void *obj)
 {
