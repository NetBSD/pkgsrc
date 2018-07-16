$NetBSD: patch-res_res__pjsip_location.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip/location.c.orig	2018-06-20 15:05:13.082730303 +0000
+++ res/res_pjsip/location.c
@@ -17,21 +17,22 @@
  */
 
 #include "asterisk.h"
-#include <pjsip.h>
-#include <pjlib.h>
-
-#include "asterisk/res_pjsip.h"
 #include "asterisk/logger.h"
 #include "asterisk/astobj2.h"
 #include "asterisk/paths.h"
 #include "asterisk/sorcery.h"
 #include "asterisk/taskprocessor.h"
-#include "include/res_pjsip_private.h"
-#include "asterisk/res_pjsip_cli.h"
 #include "asterisk/statsd.h"
 #include "asterisk/named_locks.h"
 
+
+#include <pjsip.h>
+#include <pjlib.h>
+
+#include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjproject.h"
+#include "asterisk/res_pjsip_cli.h"
+#include "include/res_pjsip_private.h"
 
 static int pj_max_hostname = PJ_MAX_HOSTNAME;
 static int pjsip_max_url_size = PJSIP_MAX_URL_SIZE;
