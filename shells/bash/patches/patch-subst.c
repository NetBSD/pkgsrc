$NetBSD: patch-subst.c,v 1.1 2020/03/17 17:09:48 rillig Exp $

Fix array subscript with char index.

--- subst.c.orig	2020-03-17 16:57:17.469764555 +0000
+++ subst.c
@@ -11294,7 +11294,7 @@ shell_expand_word_list (tlist, eflags)
 			case 'l':
 			case 'u':
 			case 'c':
-			  omap[l->word->word[oind]] = 1;
+			  omap[(unsigned char) l->word->word[oind]] = 1;
 			  if (opti == 0)
 			    opts[opti++] = '-';
 			  break;
