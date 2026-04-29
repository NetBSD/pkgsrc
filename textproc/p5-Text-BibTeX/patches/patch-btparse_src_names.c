$NetBSD: patch-btparse_src_names.c,v 1.1 2026/04/29 21:08:25 markd Exp $

Fix ctype(3) usage.

--- ./btparse/src/names.c.orig	2025-01-29 15:47:18.000000000 +0000
+++ ./btparse/src/names.c
@@ -157,7 +157,7 @@ bt_split_list (char *   string,
    while (i < maxoffs)
    {
       /* does current char. in string match current char. in delim? */
-      if (depth == 0 && !inword && tolower (string[i]) == delim[j])
+      if (depth == 0 && !inword && tolower ((unsigned char)string[i]) == delim[j])
       {
          j++; i++;
 
@@ -334,7 +334,7 @@ find_commas (name_loc * loc, char *name,
 		 --j;
 	 else /* remove following whitespace */
 		 last_whitespace = 1;
-      } else if (isspace(c)) {
+      } else if (isspace((unsigned char)c)) {
 	      /* collapse white space */
 	      if (last_whitespace) continue;
 	      else last_whitespace = 1;
