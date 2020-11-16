$NetBSD: patch-src_backend_commands_collationcmds.c,v 1.1 2020/11/16 12:15:04 adam Exp $

Fix for ICU 68.1.

--- src/backend/commands/collationcmds.c.orig	2020-11-13 08:22:04.000000000 +0000
+++ src/backend/commands/collationcmds.c
@@ -463,7 +463,7 @@ get_icu_language_tag(const char *localen
 	UErrorCode	status;
 
 	status = U_ZERO_ERROR;
-	uloc_toLanguageTag(localename, buf, sizeof(buf), TRUE, &status);
+	uloc_toLanguageTag(localename, buf, sizeof(buf), true, &status);
 	if (U_FAILURE(status))
 		ereport(ERROR,
 				(errmsg("could not convert locale name \"%s\" to language tag: %s",
