$NetBSD: patch-res_res__pjsip_config__transport.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip/config_transport.c.orig	2018-06-20 15:08:28.782330643 +0000
+++ res/res_pjsip/config_transport.c
@@ -19,19 +19,21 @@
 #include "asterisk.h"
 
 #include <math.h>
-#include <pjsip.h>
-#include <pjlib.h>
 
-#include "asterisk/res_pjsip.h"
-#include "asterisk/res_pjsip_cli.h"
 #include "asterisk/logger.h"
 #include "asterisk/astobj2.h"
 #include "asterisk/sorcery.h"
 #include "asterisk/acl.h"
 #include "asterisk/utils.h"
-#include "include/res_pjsip_private.h"
 #include "asterisk/http_websocket.h"
 
+#include <pjsip.h>
+#include <pjlib.h>
+
+#include "asterisk/res_pjsip.h"
+#include "asterisk/res_pjsip_cli.h"
+#include "include/res_pjsip_private.h"
+
 #define MAX_POINTER_STRING 33
 
 /*! \brief Default number of state container buckets */
