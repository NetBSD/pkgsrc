$NetBSD: patch-res_res__pjsip_pjsip__configuration.c,v 1.1 2024/02/19 05:59:52 jnemeth Exp $

--- res/res_pjsip/pjsip_configuration.c.orig	2022-04-14 21:53:34.000000000 +0000
+++ res/res_pjsip/pjsip_configuration.c
@@ -1039,7 +1039,7 @@ static int from_user_handler(const struc
 	const char *val;
 
 	for (val = var->value; *val; val++) {
-		if (!isalpha(*val) && !isdigit(*val) && !strchr(valid_uri_marks, *val)) {
+		if (!isalpha((unsigned char)*val) && !isdigit((unsigned char)*val) && !strchr(valid_uri_marks, *val)) {
 			ast_log(LOG_ERROR, "Error configuring endpoint '%s' - '%s' field "
 			"contains invalid character '%c'\n",
 			ast_sorcery_object_get_id(endpoint), var->name, *val);
