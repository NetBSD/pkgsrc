$NetBSD: patch-res_res__pjsip__publish__asterisk.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_publish_asterisk.c.orig	2018-06-20 15:15:27.126012722 +0000
+++ res/res_pjsip_publish_asterisk.c
@@ -28,15 +28,16 @@
 
 #include <regex.h>
 
+#include "asterisk/module.h"
+#include "asterisk/logger.h"
+#include "asterisk/app.h"
+
 #include <pjsip.h>
 #include <pjsip_simple.h>
 
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_outbound_publish.h"
 #include "asterisk/res_pjsip_pubsub.h"
-#include "asterisk/module.h"
-#include "asterisk/logger.h"
-#include "asterisk/app.h"
 
 /*** DOCUMENTATION
 	<configInfo name="res_pjsip_publish_asterisk" language="en_US">
