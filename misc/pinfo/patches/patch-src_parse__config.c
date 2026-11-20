$NetBSD: patch-src_parse__config.c,v 1.1 2026/11/20 15:57:11 ktnb Exp $

ctype fix for NetBSD 11

--- src/parse_config.c.orig	2026-11-20 14:27:58.428941106 +0000
+++ src/parse_config.c
@@ -895,7 +895,7 @@ parse_line(char *line)
 					{
 						if (temp[1] == '\'')
 							*key = KEY_CTRL(temp[2]);
-						else if (isdigit(temp[1]))
+						else if (isdigit((unsigned char)temp[1]))
 						{
 							char *tail = temp +(strlen(temp));
 							*key = KEY_CTRL((int) strtol(temp + 1, &tail, 10));
@@ -913,8 +913,8 @@ parse_line(char *line)
 					if (temp[0] == '(')
 					{
 						if (temp[1] == '\'')
-							*key = KEY_ALT(tolower(temp[2]));
-						else if (isdigit(temp[1]))
+							*key = KEY_ALT(tolower((unsigned char)temp[2]));
+						else if (isdigit((unsigned char)temp[1]))
 						{
 							char *tail = temp +(strlen(temp));
 							*key = KEY_ALT((int) strtol(temp + 1, &tail, 10));
@@ -948,7 +948,7 @@ parse_line(char *line)
 					*key = temp[1];
 				}
 			}
-			else if (isdigit(temp[0]))
+			else if (isdigit((unsigned char)temp[0]))
 			{
 				char *tail = temp +(strlen(temp));
 				*key =(int) strtol(temp, &tail, 10);
@@ -963,8 +963,8 @@ str_toupper(char *str)
 {
 	unsigned int i;
 	for (i = 0; i < strlen(str); ++i)
-		if (islower(str[i]))
-			str[i] = toupper(str[i]);
+		if (islower((unsigned char)str[i]))
+			str[i] = toupper((unsigned char)str[i]);
 
 	return str;
 }
