$NetBSD: patch-jedec.c,v 1.2 2024/04/21 20:37:52 thorpej Exp $

Use ctype(3) functions safely.

--- jedec.c.orig	2024-04-21 20:28:47.620230367 +0000
+++ jedec.c	2024-04-21 20:30:15.920088540 +0000
@@ -146,7 +146,7 @@ static int parse_tokens(char *buffer, si
 			continue;
 
 		/* Skip non printable characters but ETX */
-		while (!isalpha((int)*p_token) && *p_token != ETX)
+		while (!isalpha((unsigned char)*p_token) && *p_token != ETX)
 			p_token++;
 
 		/* Exit the loop if the ETX character is found */
@@ -274,7 +274,7 @@ static int parse_tokens(char *buffer, si
 			 * 120 bits row.
 			 */
 			while (*p_next != DELIMITER) {
-				if (!iscntrl((int)*p_next) && *p_next != ' ' &&
+				if (!iscntrl((unsigned char)*p_next) && *p_next != ' ' &&
 				    *p_next != '0' && *p_next != '1')
 					return BAD_FORMAT;
 
