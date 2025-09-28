$NetBSD: patch-atk-adaptor_event.c,v 1.1 2025/09/28 15:55:43 prlw1 Exp $

warning: array subscript has type 'char'

--- atk-adaptor/event.c.orig	2025-09-13 14:41:15.000000000 +0000
+++ atk-adaptor/event.c
@@ -356,11 +356,11 @@ signal_name_to_dbus (const gchar *s)
 
   if (!ret)
     return NULL;
-  ret[0] = toupper (ret[0]);
+  ret[0] = toupper ((unsigned char)ret[0]);
   while ((t = strchr (ret, '-')) != NULL)
     {
       memmove (t, t + 1, strlen (t));
-      *t = toupper (*t);
+      *t = toupper ((unsigned char)*t);
     }
   return ret;
 }
@@ -382,7 +382,7 @@ ensure_proper_format (const char *name)
     {
       if (need_upper)
         {
-          *p++ = toupper (*name);
+          *p++ = toupper ((unsigned char)*name);
           need_upper = FALSE;
         }
       else if (*name == '-')
