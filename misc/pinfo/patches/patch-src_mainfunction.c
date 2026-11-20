$NetBSD: patch-src_mainfunction.c,v 1.2 2026/11/20 20:24:55 ktnb Exp $

ctype fix for NetBSD 11, fix bug when there is no readline

--- src/mainfunction.c.orig	2019-02-16 20:23:32.000000000 +0000
+++ src/mainfunction.c
@@ -233,7 +233,7 @@ work(char ***message, char **type, unsigned long *line
 					int digit_val = 1;
 					for (unsigned i = 0; token[i] != 0; i++)
 					{
-						if (!isdigit(token[i]))
+						if (!isdigit((unsigned char)token[i]))
 							digit_val = 0;
 					}
 					if (digit_val)	/* go to specified line */
@@ -673,7 +673,11 @@ skip_search:
 				curs_set(1);
 
 				const char ** tag_completions = completions_from_tag_table(tag_table, TagTableEntries);
+#ifdef HAS_READLINE
 				token = getstring_with_completion(_("Enter node name: "), tag_completions);	/* read user's wish */
+#else
+				token = getstring_with_completion(_("Enter node name: "));	/* read user's wish */
+#endif
 				if (tag_completions!=NULL)
 				{
 					free(tag_completions);
