$NetBSD: patch-src_jedec.c,v 1.1 2025/04/27 17:46:01 thorpej Exp $

Use ctype(3) functions safely.

--- src/jedec.c.orig	2025-04-27 16:29:38
+++ src/jedec.c	2025-04-27 16:30:03
@@ -146,7 +146,7 @@ static int parse_tokens(char *buffer, size_t buffer_si
 			continue;
 
 		/* Skip non printable characters but ETX */
-		while (!isalpha((int)*p_token) && *p_token != ETX)
+		while (!isalpha((unsigned char)*p_token) && *p_token != ETX)
 			p_token++;
 
 		/* Exit the loop if the ETX character is found */
@@ -274,7 +274,7 @@ static int parse_tokens(char *buffer, size_t buffer_si
 			 * 120 bits row.
 			 */
 			while (*p_next != DELIMITER) {
-				if (!iscntrl((int)*p_next) && *p_next != ' ' &&
+				if (!iscntrl((unsigned char)*p_next) && *p_next != ' ' &&
 				    *p_next != '0' && *p_next != '1')
 					return BAD_FORMAT;
 
