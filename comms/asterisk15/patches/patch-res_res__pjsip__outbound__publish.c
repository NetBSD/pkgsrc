$NetBSD: patch-res_res__pjsip__outbound__publish.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_outbound_publish.c.orig	2018-06-20 15:25:56.444583849 +0000
+++ res/res_pjsip_outbound_publish.c
@@ -25,16 +25,17 @@
 
 #include "asterisk.h"
 
+#include "asterisk/module.h"
+#include "asterisk/taskprocessor.h"
+#include "asterisk/threadpool.h"
+#include "asterisk/datastore.h"
+
 #include <pjsip.h>
 #include <pjsip_simple.h>
 
 #include "asterisk/res_pjproject.h"
 #include "asterisk/res_pjsip.h"
 #include "asterisk/res_pjsip_outbound_publish.h"
-#include "asterisk/module.h"
-#include "asterisk/taskprocessor.h"
-#include "asterisk/threadpool.h"
-#include "asterisk/datastore.h"
 #include "res_pjsip/include/res_pjsip_private.h"
 
 /*** DOCUMENTATION
