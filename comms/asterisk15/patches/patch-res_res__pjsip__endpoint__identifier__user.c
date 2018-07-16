$NetBSD: patch-res_res__pjsip__endpoint__identifier__user.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_endpoint_identifier_user.c.orig	2018-06-20 15:14:17.549119230 +0000
+++ res/res_pjsip_endpoint_identifier_user.c
@@ -24,10 +24,11 @@
 
 #include "asterisk.h"
 
+#include "asterisk/module.h"
+
 #include <pjsip.h>
 
 #include "asterisk/res_pjsip.h"
-#include "asterisk/module.h"
 
 static int get_from_header(pjsip_rx_data *rdata, char *username, size_t username_size, char *domain, size_t domain_size)
 {
