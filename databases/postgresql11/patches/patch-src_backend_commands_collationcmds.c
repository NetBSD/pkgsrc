$NetBSD: patch-src_backend_commands_collationcmds.c,v 1.1 2020/11/06 21:38:30 otis Exp $

Change TRUE to true

--- src/backend/commands/collationcmds.c.orig	2020-08-10 21:17:40.000000000 +0000
+++ src/backend/commands/collationcmds.c
@@ -444,7 +444,7 @@ get_icu_language_tag(const char *localen
 	UErrorCode	status;
 
 	status = U_ZERO_ERROR;
-	uloc_toLanguageTag(localename, buf, sizeof(buf), TRUE, &status);
+	uloc_toLanguageTag(localename, buf, sizeof(buf), true, &status);
 	if (U_FAILURE(status))
 		ereport(ERROR,
 				(errmsg("could not convert locale name \"%s\" to language tag: %s",
