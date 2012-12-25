$NetBSD: patch-src_syncml__plugin.c,v 1.1 2012/12/25 21:13:19 joerg Exp $

--- src/syncml_plugin.c.orig	2012-12-25 17:29:15.000000000 +0000
+++ src/syncml_plugin.c
@@ -1297,7 +1297,7 @@ static void batch_commit(OSyncContext *c
 
 	for (i = 0; i < num; i++) {
 		if (contexts[i]) {
-			osync_context_report_error(contexts[i], SML_ERROR_GENERIC, "content type was not configured");
+			osync_context_report_error(contexts[i], OSYNC_ERROR_GENERIC, "content type was not configured");
 		}
 	}
 
