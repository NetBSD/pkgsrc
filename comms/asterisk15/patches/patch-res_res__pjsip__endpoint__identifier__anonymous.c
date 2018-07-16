$NetBSD: patch-res_res__pjsip__endpoint__identifier__anonymous.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_endpoint_identifier_anonymous.c.orig	2018-06-20 14:51:13.694673514 +0000
+++ res/res_pjsip_endpoint_identifier_anonymous.c
@@ -24,11 +24,11 @@
  ***/
 
 #include "asterisk.h"
+#include "asterisk/module.h"
 
 #include <pjsip.h>
 
 #include "asterisk/res_pjsip.h"
-#include "asterisk/module.h"
 
 static int get_endpoint_details(pjsip_rx_data *rdata, char *domain, size_t domain_size)
 {
