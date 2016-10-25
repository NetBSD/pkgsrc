$NetBSD: patch-tests_test__voicemail__api.c,v 1.1.1.1 2016/10/25 08:17:08 jnemeth Exp $

--- tests/test_voicemail_api.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ tests/test_voicemail_api.c
@@ -383,7 +383,7 @@ static struct ast_vm_msg_snapshot *test_
 	struct ast_vm_msg_snapshot *snapshot;
 
 	snprintf(msg_id_hash, sizeof(msg_id_hash), "%s%s%s", exten, context, callerid);
-	snprintf(msg_id_buf, sizeof(msg_id_buf), "%ld-%d", (long)time(NULL), ast_str_hash(msg_id_hash));
+	snprintf(msg_id_buf, sizeof(msg_id_buf), "%jd-%d", (intmax_t)time(NULL), ast_str_hash(msg_id_hash));
 
 	if ((snapshot = ast_calloc(1, sizeof(*snapshot)))) {
 		if (ast_string_field_init(snapshot, 128)) {
