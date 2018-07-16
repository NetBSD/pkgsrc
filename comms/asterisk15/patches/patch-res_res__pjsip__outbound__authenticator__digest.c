$NetBSD: patch-res_res__pjsip__outbound__authenticator__digest.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip_outbound_authenticator_digest.c.orig	2018-06-20 15:22:43.400330893 +0000
+++ res/res_pjsip_outbound_authenticator_digest.c
@@ -24,13 +24,14 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-
-#include "asterisk/res_pjsip.h"
 #include "asterisk/logger.h"
 #include "asterisk/module.h"
 #include "asterisk/strings.h"
 
+#include <pjsip.h>
+
+#include "asterisk/res_pjsip.h"
+
 static pjsip_www_authenticate_hdr *get_auth_header(pjsip_rx_data *challenge,
 	const void *start)
 {
