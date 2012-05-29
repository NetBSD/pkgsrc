$NetBSD: patch-tests_coding-test.c,v 1.1 2012/05/29 20:21:53 joerg Exp $

--- tests/coding-test.c.orig	2012-05-05 16:22:51.000000000 +0000
+++ tests/coding-test.c
@@ -46,7 +46,7 @@ server_callback (SoupServer *server, Sou
 
 	if (codings) {
 		gboolean claim_deflate, claim_gzip;
-		const char *file_path = NULL, *encoding = NULL;
+		const char *encoding = NULL, *suffix;
 
 		claim_deflate = g_slist_find_custom (codings, "deflate", (GCompareFunc)g_ascii_strcasecmp) != NULL;
 		claim_gzip = g_slist_find_custom (codings, "gzip", (GCompareFunc)g_ascii_strcasecmp) != NULL;
@@ -54,19 +54,19 @@ server_callback (SoupServer *server, Sou
 		if (claim_gzip && (!claim_deflate ||
 				   (!soup_header_contains (options, "prefer-deflate-zlib") &&
 				    !soup_header_contains (options, "prefer-deflate-raw")))) {
-			file_path = SRCDIR "/resources%s.gz";
+			suffix = ".gz";
 			encoding = "gzip";
 		} else if (claim_deflate) {
 			if (soup_header_contains (options, "prefer-deflate-raw")) {
-				file_path = SRCDIR "/resources%s.raw";
+				suffix = ".raw";
 				encoding = "deflate";
 			} else {
-				file_path = SRCDIR "/resources%s.zlib";
+				suffix = ".zlib";
 				encoding = "deflate";
 			}
 		}
-		if (file_path && encoding) {
-			file = g_strdup_printf (file_path, path);
+		if (encoding) {
+			file = g_strdup_printf (SRCDIR "/resources%s%s", path, suffix);
 			if (g_file_test (file, G_FILE_TEST_EXISTS)) {
 				soup_message_headers_append (msg->response_headers,
 							     "Content-Encoding",
