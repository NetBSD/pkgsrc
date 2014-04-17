$NetBSD: patch-src_completion.c,v 1.1 2014/04/17 20:27:33 joerg Exp $

--- src/completion.c.orig	2014-04-17 18:24:23.000000000 +0000
+++ src/completion.c
@@ -336,7 +336,7 @@ static char *local_taglist_completion_fu
  * in case we want to do some simple parsing.  Return the array of matches,
  * or NULL if there aren't any.
  */
-char **the_complete_function(char *text, int start, int end)
+char **the_complete_function(const char *text, int start, int end)
 {
     char **matches = 0;
 	cmd_t *cp;
