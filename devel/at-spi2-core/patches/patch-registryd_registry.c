$NetBSD: patch-registryd_registry.c,v 1.1 2025/09/28 15:55:43 prlw1 Exp $

warning: array subscript has type 'char'

--- registryd/registry.c.orig	2025-09-13 14:41:15.000000000 +0000
+++ registryd/registry.c
@@ -362,7 +362,7 @@ ensure_proper_format (const char *name)
     {
       if (need_upper)
         {
-          *p++ = toupper (*name);
+          *p++ = toupper ((unsigned char)*name);
           need_upper = FALSE;
         }
       else if (*name == '-')
