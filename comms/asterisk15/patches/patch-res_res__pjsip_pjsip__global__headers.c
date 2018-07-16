$NetBSD: patch-res_res__pjsip_pjsip__global__headers.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip/pjsip_global_headers.c.orig	2018-06-20 15:04:07.107055522 +0000
+++ res/res_pjsip/pjsip_global_headers.c
@@ -18,11 +18,13 @@
 
 #include "asterisk.h"
 
+#include "asterisk/linkedlists.h"
+#include "asterisk/network.h"
+
 #include <pjsip.h>
 #include <pjlib.h>
 
 #include "asterisk/res_pjsip.h"
-#include "asterisk/linkedlists.h"
 #include "include/res_pjsip_private.h"
 
 static pj_status_t add_request_headers(pjsip_tx_data *tdata);
