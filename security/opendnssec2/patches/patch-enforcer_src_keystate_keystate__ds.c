$NetBSD: patch-enforcer_src_keystate_keystate__ds.c,v 1.1 2023/12/05 12:20:40 he Exp $

Give correct upper/lower-case hint if command isn't configured
in the error message in the log and/or console.

--- enforcer/src/keystate/keystate_ds.c.orig	2020-02-10 17:25:11.000000000 +0000
+++ enforcer/src/keystate/keystate_ds.c
@@ -217,7 +217,7 @@ submit_dnskey_by_id(int sockfd, key_data
 {
 	const char* ds_submit_command;
 	ds_submit_command = engine->config->delegation_signer_submit_command;
-	return exec_dnskey_by_id(sockfd, key, ds_submit_command, "submit");
+	return exec_dnskey_by_id(sockfd, key, ds_submit_command, "Submit");
 }
 
 static int
@@ -225,7 +225,7 @@ retract_dnskey_by_id(int sockfd, key_dat
 {
 	const char* ds_retract_command;
 	ds_retract_command = engine->config->delegation_signer_retract_command;
-	return exec_dnskey_by_id(sockfd, key, ds_retract_command, "retract");
+	return exec_dnskey_by_id(sockfd, key, ds_retract_command, "Retract");
 }
 
 static int
