$NetBSD: patch-res_res__pjsip_config__global.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip/config_global.c.orig	2018-06-20 15:12:19.176643964 +0000
+++ res/res_pjsip/config_global.c
@@ -17,16 +17,16 @@
  */
 
 #include "asterisk.h"
+#include "asterisk/sorcery.h"
+#include "asterisk/taskprocessor.h"
+#include "asterisk/ast_version.h"
 
 #include <pjsip.h>
 #include <pjlib.h>
 
 #include "asterisk/res_pjsip.h"
-#include "include/res_pjsip_private.h"
-#include "asterisk/sorcery.h"
-#include "asterisk/taskprocessor.h"
-#include "asterisk/ast_version.h"
 #include "asterisk/res_pjsip_cli.h"
+#include "include/res_pjsip_private.h"
 
 #define DEFAULT_MAX_FORWARDS 70
 #define DEFAULT_KEEPALIVE_INTERVAL 0
