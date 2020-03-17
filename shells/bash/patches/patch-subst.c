$NetBSD: patch-subst.c,v 1.2 2020/03/17 21:59:48 rillig Exp $

Fix array subscript with char index.

https://lists.gnu.org/archive/html/bug-bash/2020-03/msg00056.html

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
