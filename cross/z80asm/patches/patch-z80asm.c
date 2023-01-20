$NetBSD: patch-z80asm.c,v 1.1 2023/01/20 21:43:56 thorpej Exp $

Cast arguments to ctype(3) functions to (unsigned char).  Remove a
set-but-not-used variable.

--- z80asm.c.orig	2023-01-20 20:33:15.390493731 +0000
+++ z80asm.c	2023-01-20 20:37:05.963725354 +0000
@@ -123,7 +123,7 @@ printerr (int error, const char *fmt, ..
 const char *
 delspc (const char *ptr)
 {
-  while (*ptr && isspace (*ptr))
+  while (*ptr && isspace ((unsigned char)*ptr))
     ptr++;
   if (*ptr == ';')
     ptr = "";
@@ -440,7 +440,7 @@ parse_commandline (int argc, char **argv
 static int
 indx (const char **ptr, const char **list, int error, const char **expr)
 {
-  int i, l;
+  int i;
   *ptr = delspc (*ptr);
   if (!**ptr)
     {
@@ -461,7 +461,6 @@ indx (const char **ptr, const char **lis
       int had_expr = 0;
       if (!list[i][0])
 	continue;
-      l = strlen (list[i]);
       while (*check)
 	{
 	  if (*check == ' ')
@@ -492,7 +491,7 @@ indx (const char **ptr, const char **lis
 
 	  ++check;
 	}
-      if (*check || (isalnum (check[-1]) && isalnum (input[0])))
+      if (*check || (isalnum ((unsigned char)check[-1]) && isalnum ((unsigned char)input[0])))
 	continue;
       if (had_expr)
 	{
