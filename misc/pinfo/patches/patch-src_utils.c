$NetBSD: patch-src_utils.c,v 1.1 2026/11/20 15:57:11 ktnb Exp $

ctype fix for NetBSD 11 and sys/wait.h is required

--- src/utils.c.orig	2026-11-20 14:25:26.785618991 +0000
+++ src/utils.c
@@ -24,6 +24,7 @@
 #include <regex.h>
 #include <ctype.h>
 #include <sys/select.h>
+#include <sys/wait.h>
 
 #ifdef USE_WCHAR
   #include <wchar.h>
@@ -353,7 +354,7 @@ char ** completions_from_tag_table(TagTable * table, s
 	const char ** completions = calloc(num+1, sizeof(*completions));
 	for (size_t i=0, j=0; i<num; i++)
 	{
-		if (isalnum(table[i].nodename[0]))
+		if (isalnum((unsigned char)table[i].nodename[0]))
 		{
 			completions[j++] = table[i].nodename;
 		}
@@ -604,14 +605,14 @@ yesno(char *prompt, int def)
 			break;
 		else
 		{
-			if (tolower(key) == tolower(*yes))
+			if (tolower((unsigned char)key) == tolower((unsigned char)*yes))
 			{
 				def = 1;
 				break;
 			}
 			else
 			{
-				if (tolower(key) == tolower(*no))
+				if (tolower((unsigned char)key) == tolower((unsigned char)*no))
 				{
 					def = 0;
 					break;
