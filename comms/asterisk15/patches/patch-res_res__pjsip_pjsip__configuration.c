$NetBSD: patch-res_res__pjsip_pjsip__configuration.c,v 1.1 2018/07/16 21:53:05 joerg Exp $

--- res/res_pjsip/pjsip_configuration.c.orig	2018-06-11 21:21:37.000000000 +0000
+++ res/res_pjsip/pjsip_configuration.c
@@ -18,12 +18,6 @@
 
 #include "asterisk.h"
 
-#include <pjsip.h>
-#include <pjsip_ua.h>
-
-#include "asterisk/res_pjsip.h"
-#include "include/res_pjsip_private.h"
-#include "asterisk/res_pjsip_cli.h"
 #include "asterisk/acl.h"
 #include "asterisk/manager.h"
 #include "asterisk/astobj2.h"
@@ -35,6 +29,13 @@
 #include "asterisk/pbx.h"
 #include "asterisk/stream.h"
 
+#include <pjsip.h>
+#include <pjsip_ua.h>
+
+#include "asterisk/res_pjsip.h"
+#include "include/res_pjsip_private.h"
+#include "asterisk/res_pjsip_cli.h"
+
 /*! \brief Number of buckets for persistent endpoint information */
 #define PERSISTENT_BUCKETS 53
 
@@ -1222,7 +1223,7 @@ static int from_user_handler(const struc
 	const char *val;
 
 	for (val = var->value; *val; val++) {
-		if (!isalpha(*val) && !isdigit(*val) && !strchr(valid_uri_marks, *val)) {
+		if (!isalpha((unsigned char)*val) && !isdigit((unsigned char)*val) && !strchr(valid_uri_marks, *val)) {
 			ast_log(LOG_ERROR, "Error configuring endpoint '%s' - '%s' field "
 			"contains invalid character '%c'\n",
 			ast_sorcery_object_get_id(endpoint), var->name, *val);
