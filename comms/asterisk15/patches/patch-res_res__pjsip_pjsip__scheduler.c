$NetBSD: patch-res_res__pjsip_pjsip__scheduler.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip/pjsip_scheduler.c.orig	2018-06-20 15:01:28.428240101 +0000
+++ res/res_pjsip/pjsip_scheduler.c
@@ -25,10 +25,12 @@
 
 #include "asterisk.h"
 
+#include "asterisk/network.h"
+#include "asterisk/taskprocessor.h"
+
 #include "asterisk/res_pjsip.h"
 #include "include/res_pjsip_private.h"
 #include "asterisk/res_pjsip_cli.h"
-#include "asterisk/taskprocessor.h"
 
 #define TASK_BUCKETS 53
 
