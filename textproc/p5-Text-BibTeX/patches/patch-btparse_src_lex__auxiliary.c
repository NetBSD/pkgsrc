$NetBSD: patch-btparse_src_lex__auxiliary.c,v 1.1 2026/04/29 21:08:25 markd Exp $

Fix ctype(3) usage.

--- ./btparse/src/lex_auxiliary.c.orig	2025-01-29 15:47:18.000000000 +0000
+++ ./btparse/src/lex_auxiliary.c
@@ -896,9 +896,9 @@ void check_runaway_string (void)
          guess = entry;
       }
 
-      if (strchr (alpha_chars, tolower (zzbegexpr[i])) != NULL)
+      if (strchr (alpha_chars, tolower ((unsigned char)zzbegexpr[i])) != NULL)
       {
-         while (i < len && strchr (name_chars, tolower (zzbegexpr[i])) != NULL)
+         while (i < len && strchr (name_chars, tolower ((unsigned char)zzbegexpr[i])) != NULL)
             i++;
          while (i < len && zzbegexpr[i] == ' ') i++;
          if (i == len)
