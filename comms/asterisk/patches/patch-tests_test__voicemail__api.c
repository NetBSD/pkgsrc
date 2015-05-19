$NetBSD: patch-tests_test__voicemail__api.c,v 1.1 2015/05/19 07:52:14 jnemeth Exp $

--- tests/test_voicemail_api.c.orig	2014-07-22 14:00:33.000000000 +0000
+++ tests/test_voicemail_api.c
@@ -299,7 +299,7 @@ static struct ast_vm_msg_snapshot *test_
 	struct ast_vm_msg_snapshot *snapshot;
 
 	snprintf(msg_id_hash, sizeof(msg_id_hash), "%s%s%s", exten, context, callerid);
-	snprintf(msg_id_buf, sizeof(msg_id_buf), "%ld-%d", (long)time(NULL), ast_str_hash(msg_id_hash));
+	snprintf(msg_id_buf, sizeof(msg_id_buf), "%jd-%d", (intmax_t)time(NULL), ast_str_hash(msg_id_hash));
 
 	if ((snapshot = ast_calloc(1, sizeof(*snapshot)))) {
 		if (ast_string_field_init(snapshot, 128)) {
