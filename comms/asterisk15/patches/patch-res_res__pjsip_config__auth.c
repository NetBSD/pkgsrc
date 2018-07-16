$NetBSD: patch-res_res__pjsip_config__auth.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip/config_auth.c.orig	2018-06-20 15:02:20.856250840 +0000
+++ res/res_pjsip/config_auth.c
@@ -18,12 +18,14 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-#include <pjlib.h>
-#include "asterisk/res_pjsip.h"
 #include "asterisk/logger.h"
 #include "asterisk/sorcery.h"
 #include "asterisk/cli.h"
+
+#include <pjsip.h>
+#include <pjlib.h>
+
+#include "asterisk/res_pjsip.h"
 #include "include/res_pjsip_private.h"
 #include "asterisk/res_pjsip_cli.h"
 
