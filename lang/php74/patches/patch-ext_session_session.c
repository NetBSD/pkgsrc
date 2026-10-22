$NetBSD: patch-ext_session_session.c,v 1.1 2026/10/22 02:06:45 taca Exp $

Fix for CVE-2026-109618-109619.

--- ext/session/session.c.orig	2022-10-31 10:36:09.000000000 +0000
+++ ext/session/session.c
@@ -3174,7 +3174,7 @@ static int php_session_rfc1867_callback(
 	if (php_session_rfc1867_orig_callback) {
 		retval = php_session_rfc1867_orig_callback(event, event_data, extra);
 	}
-	if (!PS(rfc1867_enabled)) {
+	if (!PS(rfc1867_enabled) || true) {
 		return retval;
 	}
 
