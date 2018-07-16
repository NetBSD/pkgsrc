$NetBSD: patch-res_res__pjsip_config__system.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip/config_system.c.orig	2018-06-20 15:09:27.717943335 +0000
+++ res/res_pjsip/config_system.c
@@ -18,14 +18,15 @@
 
 #include "asterisk.h"
 
+#include "asterisk/sorcery.h"
+#include "asterisk/threadpool.h"
+#include "asterisk/dns.h"
+
 #include <pjsip.h>
 #include <pjlib.h>
 
 #include "asterisk/res_pjsip.h"
-#include "asterisk/sorcery.h"
 #include "include/res_pjsip_private.h"
-#include "asterisk/threadpool.h"
-#include "asterisk/dns.h"
 #include "asterisk/res_pjsip_cli.h"
 
 #define TIMER_T1_MIN 100
