$NetBSD: patch-main_SAPI.c,v 1.1 2012/04/05 03:17:26 taca Exp $

* Fix possible newline injection problem of header() function from PHP 5.4.0.

--- main/SAPI.c.orig	2012-01-01 13:15:04.000000000 +0000
+++ main/SAPI.c
@@ -590,16 +590,26 @@ SAPI_API int sapi_header_op(sapi_header_
 			return FAILURE;
 		}
 	} else {
-		/* new line safety check */
-		char *s = header_line, *e = header_line + header_line_len, *p;
-		while (s < e && (p = memchr(s, '\n', (e - s)))) {
-			if (*(p + 1) == ' ' || *(p + 1) == '\t') {
-				s = p + 1;
-				continue;
+		/* new line/NUL character safety check */
+		int i;
+		for (i = 0; i < header_line_len; i++) {
+			/* RFC 2616 allows new lines if followed by SP or HT */
+			int illegal_break =
+					(header_line[i+1] != ' ' && header_line[i+1] != '\t')
+					&& (
+						header_line[i] == '\n'
+						|| (header_line[i] == '\r' && header_line[i+1] != '\n'));
+			if (illegal_break) {
+				efree(header_line);
+				sapi_module.sapi_error(E_WARNING, "Header may not contain "
+						"more than a single header, new line detected");
+				return FAILURE;
+			}
+			if (header_line[i] == '\0') {
+				efree(header_line);
+				sapi_module.sapi_error(E_WARNING, "Header may not contain NUL bytes");
+				return FAILURE;
 			}
-			efree(header_line);
-			sapi_module.sapi_error(E_WARNING, "Header may not contain more than a single header, new line detected.");
-			return FAILURE;
 		}
 	}
 
