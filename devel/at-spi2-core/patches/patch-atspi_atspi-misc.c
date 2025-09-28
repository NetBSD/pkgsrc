$NetBSD: patch-atspi_atspi-misc.c,v 1.1 2025/09/28 15:55:43 prlw1 Exp $

warning: array subscript has type 'char'

--- atspi/atspi-misc.c.orig	2025-09-13 14:41:15.000000000 +0000
+++ atspi/atspi-misc.c
@@ -2189,18 +2189,18 @@ _atspi_strdup_and_adjust_for_dbus (const
       if (*p == '-')
         {
           memmove (p, p + 1, g_utf8_strlen (p, -1));
-          *p = toupper (*p);
+          *p = toupper ((unsigned char)*p);
         }
       else if (*p == ':')
         {
           parts++;
           if (parts == 2)
             break;
-          p[1] = toupper (p[1]);
+          p[1] = toupper ((unsigned char)p[1]);
         }
     }
 
-  d[0] = toupper (d[0]);
+  d[0] = toupper ((unsigned char)d[0]);
   return d;
 }
 
