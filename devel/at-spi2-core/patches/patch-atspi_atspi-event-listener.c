$NetBSD: patch-atspi_atspi-event-listener.c,v 1.1 2025/09/28 15:55:43 prlw1 Exp $

warning: array subscript has type 'char'

--- atspi/atspi-event-listener.c.orig	2025-09-13 14:41:15.000000000 +0000
+++ atspi/atspi-event-listener.c
@@ -200,11 +200,11 @@ convert_name_from_dbus (const char *name
 
   while (*p)
     {
-      if (isupper (*p))
+      if (isupper ((unsigned char)*p))
         {
           if (q > ret)
             *q++ = '-';
-          *q++ = tolower (*p++);
+          *q++ = tolower ((unsigned char)(*p++));
         }
       else if (path_hack && *p == '/')
         {
