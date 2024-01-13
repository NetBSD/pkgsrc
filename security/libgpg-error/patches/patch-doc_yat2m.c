$NetBSD: patch-doc_yat2m.c,v 1.1 2024/01/13 04:16:24 riastradh Exp $

Avoid ctype(3) abuse.

--- doc/yat2m.c.orig	2022-10-07 08:20:16.000000000 +0000
+++ doc/yat2m.c
@@ -374,7 +374,7 @@ ascii_strupr (char *string)
 
   for (p = string; *p; p++)
     if (!(*p & 0x80))
-      *p = toupper (*p);
+      *p = toupper ((unsigned char)*p);
   return string;
 }
 
@@ -500,7 +500,7 @@ macro_set_p (const char *name)
         break;
   if (!m || !m->value || !*m->value)
     return 0;
-  if ((*m->value & 0x80) || !isdigit (*m->value))
+  if ((*m->value & 0x80) || !isdigit ((unsigned char)*m->value))
     return 1; /* Not a digit but some other string.  */
   return !!atoi (m->value);
 }
