$NetBSD: patch-jedec.c,v 1.1 2022/01/22 17:52:53 thorpej Exp $

Use ctype(3) functions safely.

--- jedec.c.orig	2022-01-22 15:54:35.000000000 +0000
+++ jedec.c
@@ -125,7 +125,7 @@ static int parse_tokens(char *buffer, si
     if (!*p_token) continue;
 
     // Skip non printable characters but ETX
-    while (!isalpha(*p_token) && *p_token != ETX) p_token++;
+    while (!isalpha((unsigned char)*p_token) && *p_token != ETX) p_token++;
 
     // Exit the loop if the ETX character is found
     if (*p_token == ETX) break;
@@ -237,7 +237,7 @@ static int parse_tokens(char *buffer, si
          We need to parse each line to get the entire 120 bits row.
          */
         while (*p_next != DELIMITER) {
-          if (!iscntrl(*p_next) && *p_next != ' ' && *p_next != '0' &&
+          if (!iscntrl((unsigned char)*p_next) && *p_next != ' ' && *p_next != '0' &&
               *p_next != '1')
             return BAD_FORMAT;
 
