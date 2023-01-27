$NetBSD: patch-expressions.c,v 1.2 2023/01/27 23:22:31 thorpej Exp $

- Cast arguments to ctype(3) functions to (unsigned char).
- Fix a bug in "?label" expressions that caused the expressions testing
  for the existence of the label that doesn't exist (which is what the
  expression is for) to always fail with an "non-existent label" error.

--- expressions.c.orig	2009-04-11 08:33:07.000000000 +0000
+++ expressions.c	2023-01-27 23:10:00.636129136 +0000
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
@@ -402,6 +402,7 @@ rd_value (const char **p, int *valid, in
     case '@':
       return not ^ (sign * rd_otherbasenumber (p, valid, print_errors));
     case '?':
+      ++*p;
       rd_label (p, &exist, NULL, level, 0);
       return not ^ (sign * exist);
     case '&':
