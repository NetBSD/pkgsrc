$NetBSD: patch-src_utils.c,v 1.2 2026/11/20 20:24:55 ktnb Exp $

ctype fix for NetBSD 11, sys/wait.h is required, and fix readline conditional

--- src/utils.c.orig	2019-02-16 20:23:32.000000000 +0000
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
@@ -365,15 +366,18 @@ getstring(char *prompt)
 char *
 getstring(char *prompt)
 {
+#ifdef HAS_READLINE
 	return getstring_with_completion(prompt, NULL);
+#else
+	return getstring_with_completion(prompt);
+#endif
 }
-
+#ifdef HAS_READLINE
 char *
 getstring_with_completion(char *prompt, const char * const * completions)
 {
 	char *buf;
 
-#ifdef HAS_READLINE
 	completion_values = completions;
 	rl_attempted_completion_function = getstring_completion;
 	rl_completion_display_matches_hook = my_rl_completion_display;
@@ -393,15 +397,20 @@ getstring_with_completion(char *prompt, const char * c
 
 	curs_set(0);
 
+	return buf;
+}
 #else
+char *
+getstring_with_completion(char *prompt)
+{
+	char *buf;
 
 	move(maxy - 1, 0);
 	buf = readlinewrapper(prompt);
 
-#endif
-
 	return buf;
 }
+#endif
 
 void
 init_curses()
@@ -604,14 +613,14 @@ yesno(char *prompt, int def)
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
