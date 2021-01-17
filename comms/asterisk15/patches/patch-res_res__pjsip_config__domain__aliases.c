$NetBSD: patch-res_res__pjsip_config__domain__aliases.c,v 1.2 2021/01/17 08:32:40 jnemeth Exp $

--- res/res_pjsip/config_domain_aliases.c.orig	2019-09-05 13:09:20.000000000 +0000
+++ res/res_pjsip/config_domain_aliases.c
@@ -17,14 +17,14 @@
  */
 
 #include "asterisk.h"
+#include "asterisk/logger.h"
+#include "asterisk/sorcery.h"
 
 #include <pjsip.h>
 #include <pjlib.h>
 
 #include "asterisk/res_pjsip.h"
 #include "include/res_pjsip_private.h"
-#include "asterisk/logger.h"
-#include "asterisk/sorcery.h"
 
 static void domain_alias_destroy(void *obj)
 {
