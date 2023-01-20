$NetBSD: patch-expressions.c,v 1.1 2023/01/20 21:43:56 thorpej Exp $

Cast arguments to ctype(3) functions to (unsigned char).

--- expressions.c.orig	2009-04-11 08:33:07.000000000 +0000
+++ expressions.c	2023-01-20 20:44:01.470323352 +0000
@@ -48,7 +48,7 @@ rd_number (const char **p, const char **
 	     "(string=%s).\n", stack[sp].line, addr, base, *p);
   num[base] = '\0';
   *p = delspc (*p);
-  while (**p && (c = strchr (num, tolower (**p))))
+  while (**p && (c = strchr (num, tolower ((unsigned char)**p))))
     {
       i = c - num;
       if (verbose >= 7)
@@ -83,7 +83,7 @@ rd_otherbasenumber (const char **p, int 
 	printerr (1, "unexpected end of line after `@'\n");
       return 0;
     }
-  if (**p == '0' || !isalnum (**p))
+  if (**p == '0' || !isalnum ((unsigned char)**p))
     {
       if (valid)
 	*valid = 0;
@@ -93,8 +93,8 @@ rd_otherbasenumber (const char **p, int 
     }
   c = **p;
   (*p)++;
-  if (isalpha (**p))
-    return rd_number (p, NULL, tolower (c) - 'a' + 1);
+  if (isalpha ((unsigned char)**p))
+    return rd_number (p, NULL, tolower ((unsigned char)c) - 'a' + 1);
   return rd_number (p, NULL, c - '0' + 1);
 }
 
@@ -189,7 +189,7 @@ check_label (struct label *labels, const
   const char *c;
   unsigned s2;
   *p = delspc (*p);
-  for (c = *p; isalnum (*c) || *c == '_' || *c == '.'; ++c)
+  for (c = *p; isalnum ((unsigned char)*c) || *c == '_' || *c == '.'; ++c)
     {
     }
   s2 = c - *p;
