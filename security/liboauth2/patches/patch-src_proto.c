$NetBSD: patch-src_proto.c,v 1.1 2026/06/13 11:06:10 markd Exp $

error: array subscript has type 'char'

--- src/proto.c.orig	2026-06-03 16:26:36.000000000 +0000
+++ src/proto.c
@@ -67,7 +67,7 @@ _oauth2_get_source_token_from_header(oau
 		}
 	}
 
-	while (isspace(*auth_line))
+	while (isspace((unsigned char)*auth_line))
 		auth_line++;
 	source_token = oauth2_strdup(auth_line);
 
@@ -262,7 +262,7 @@ static char *_oauth2_get_source_token_fr
 			    scheme);
 		goto end;
 	}
-	while (isspace(*auth_line))
+	while (isspace((unsigned char)*auth_line))
 		auth_line++;
 
 	if (oauth2_base64_decode(log, auth_line, (uint8_t **)&decoded_line,
