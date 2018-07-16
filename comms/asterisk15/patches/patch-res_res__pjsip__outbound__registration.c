$NetBSD: patch-res_res__pjsip__outbound__registration.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_outbound_registration.c.orig	2018-06-20 14:52:22.011336029 +0000
+++ res/res_pjsip_outbound_registration.c
@@ -25,11 +25,6 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-#include <pjsip_ua.h>
-
-#include "asterisk/res_pjsip.h"
-#include "asterisk/res_pjsip_cli.h"
 #include "asterisk/module.h"
 #include "asterisk/taskprocessor.h"
 #include "asterisk/cli.h"
@@ -37,6 +32,12 @@
 #include "asterisk/threadstorage.h"
 #include "asterisk/threadpool.h"
 #include "asterisk/statsd.h"
+
+#include <pjsip.h>
+#include <pjsip_ua.h>
+
+#include "asterisk/res_pjsip.h"
+#include "asterisk/res_pjsip_cli.h"
 #include "res_pjsip/include/res_pjsip_private.h"
 
 /*** DOCUMENTATION
