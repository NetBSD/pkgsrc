$NetBSD: patch-src_argparse.c,v 1.1 2024/01/13 04:16:24 riastradh Exp $

Fix ctype(3) abuse.

--- src/argparse.c.orig	2023-01-17 08:46:53.000000000 +0000
+++ src/argparse.c
@@ -826,8 +826,8 @@ substitute_vars (gpgrt_argparse_t *arg, 
         }
       else
         {
-          for (pend = p+1; (*pend && isascii (*p)
-                            && (isalnum (*pend) || *pend == '_')); pend++)
+          for (pend = p+1; (*pend && isascii ((unsigned char)*p)
+                            && (isalnum ((unsigned char)*pend) || *pend == '_')); pend++)
             ;
         }
 
@@ -1050,20 +1050,20 @@ handle_meta_if (gpgrt_argparse_t *arg, u
       return 0;
     }
 
-  for (p = str1; *p && !(isascii (*p) && isspace (*p)); p++)
+  for (p = str1; *p && !(isascii ((unsigned char)*p) && isspace ((unsigned char)*p)); p++)
     ;
   if (*p)
     {
       *p++ = 0;
-      for (; *p && isascii (*p) && isspace (*p); p++)
+      for (; *p && isascii ((unsigned char)*p) && isspace ((unsigned char)*p); p++)
         ;
       op = p;
-      for (; *p && !(isascii (*p) && isspace (*p)); p++)
+      for (; *p && !(isascii ((unsigned char)*p) && isspace ((unsigned char)*p)); p++)
         ;
       if (*p)
         {
           *p++ = 0;
-          for (; *p && isascii (*p) && isspace (*p); p++)
+          for (; *p && isascii ((unsigned char)*p) && isspace ((unsigned char)*p); p++)
             ;
           if (*p)
             str2 = p;
@@ -1207,7 +1207,7 @@ handle_meta_let (gpgrt_argparse_t *arg, 
   int rc;
   variable_t v;
 
-  for (value = name; *value && !(isascii (*value) && isspace (*value)); value++)
+  for (value = name; *value && !(isascii ((unsigned char)*value) && isspace ((unsigned char)*value)); value++)
     ;
   if (*value)
     {
@@ -1215,7 +1215,7 @@ handle_meta_let (gpgrt_argparse_t *arg, 
       trim_spaces (value);
     }
 
-  if (!isascii (*name) || !isalpha (*name))
+  if (!isascii ((unsigned char)*name) || !isalpha ((unsigned char)*name))
     return 0; /* Ignore setting a system or invalid variable.  */
 
   if (alternate)
@@ -1259,7 +1259,7 @@ handle_meta_getenv (gpgrt_argparse_t *ar
 #endif
 
   for (varname = name;
-       *varname && !(isascii (*varname) && isspace (*varname));
+       *varname && !(isascii ((unsigned char)*varname) && isspace ((unsigned char)*varname));
        varname++)
     ;
   if (*varname)
@@ -1268,7 +1268,7 @@ handle_meta_getenv (gpgrt_argparse_t *ar
       trim_spaces (varname);
     }
 
-  if (!isascii (*name) || !isalpha (*name))
+  if (!isascii ((unsigned char)*name) || !isalpha ((unsigned char)*name))
     return 0; /* Ignore setting a system or invalid variable.  */
 
   if (!*varname)
@@ -1430,7 +1430,7 @@ handle_metacmd (gpgrt_argparse_t *arg, c
   char *rest;
   int i;
 
-  for (rest = keyword; *rest && !(isascii (*rest) && isspace (*rest)); rest++)
+  for (rest = keyword; *rest && !(isascii ((unsigned char)*rest) && isspace ((unsigned char)*rest)); rest++)
     ;
   if (*rest)
     {
@@ -2867,7 +2867,7 @@ set_opt_arg (gpgrt_argparse_t *arg, unsi
       return 0;
 
     case ARGPARSE_TYPE_ULONG:
-      while (isascii (*s) && isspace(*s))
+      while (isascii ((unsigned char)*s) && isspace((unsigned char)*s))
         s++;
       if (*s == '-')
         {
