$NetBSD: patch-res_res__pjsip__logger.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_logger.c.orig	2018-06-20 14:45:55.987678816 +0000
+++ res/res_pjsip_logger.c
@@ -25,14 +25,15 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-
-#include "asterisk/res_pjsip.h"
 #include "asterisk/module.h"
 #include "asterisk/logger.h"
 #include "asterisk/cli.h"
 #include "asterisk/netsock2.h"
 
+#include <pjsip.h>
+
+#include "asterisk/res_pjsip.h"
+
 enum pjsip_logging_mode {
 	LOGGING_MODE_DISABLED,    /* No logging is enabled */
 	LOGGING_MODE_ENABLED,     /* Logging is enabled */
