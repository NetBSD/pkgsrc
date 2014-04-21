$NetBSD: patch-scli_scli.c,v 1.1 2014/04/21 18:13:57 joerg Exp $

--- scli/scli.c.orig	2014-04-20 18:56:10.000000000 +0000
+++ scli/scli.c
@@ -216,7 +216,7 @@ generator(char const *text, int state)
  */
 
 static char**
-completion(char *text, int start, int end)
+completion(const char *text, int start, int end)
 {
     char **matches;
 
@@ -262,7 +262,7 @@ readline_init()
     rl_readline_name = "scli";
 
     /* Tell the completer that we want a crack first. */
-    rl_attempted_completion_function = (CPPFunction *) completion;
+    rl_attempted_completion_function = completion;
 }
 
 /*
