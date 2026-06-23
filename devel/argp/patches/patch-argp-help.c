$NetBSD: patch-argp-help.c,v 1.3 2026/06/23 09:52:25 wiz Exp $

Fix ctype(3) usage.

--- argp-help.c.orig	2026-06-23 09:46:08.262497366 +0000
+++ argp-help.c
@@ -176,7 +176,7 @@ fill_in_uparams(const struct argp_state* state)
 #define SKIPWS(p)                                                                                  \
     do                                                                                             \
     {                                                                                              \
-        while (isspace(*p))                                                                        \
+        while (isspace((unsigned char)*p))                                                                        \
             p++;                                                                                   \
     } while (0);
 
@@ -186,14 +186,14 @@ fill_in_uparams(const struct argp_state* state)
         {
             SKIPWS(var);
 
-            if (isalpha(*var))
+            if (isalpha((unsigned char)*var))
             {
                 size_t var_len;
                 const struct uparam_name* un;
                 int unspec = 0, val = 0;
                 const char* arg = var;
 
-                while (isalnum(*arg) || *arg == '-' || *arg == '_')
+                while (isalnum((unsigned char)*arg) || *arg == '-' || *arg == '_')
                     arg++;
                 var_len = arg - var;
 
@@ -218,10 +218,10 @@ fill_in_uparams(const struct argp_state* state)
                     else
                         val = 1;
                 }
-                else if (isdigit(*arg))
+                else if (isdigit((unsigned char)*arg))
                 {
                     val = atoi(arg);
-                    while (isdigit(*arg))
+                    while (isdigit((unsigned char)*arg))
                         arg++;
                     SKIPWS(arg);
                 }
@@ -732,12 +732,12 @@ canon_doc_option(const char** name)
 {
     int non_opt;
     /* Skip initial whitespace.  */
-    while (isspace(**name))
+    while (isspace((unsigned char)**name))
         (*name)++;
     /* Decide whether this looks like an option (leading `-') or not.  */
     non_opt = (**name != '-');
     /* Skip until part of name used for sorting.  */
-    while (**name && !isalnum(**name))
+    while (**name && !isalnum((unsigned char)**name))
         (*name)++;
     return non_opt;
 }
