$NetBSD: patch-src_iop_lens.c,v 1.1 2012/05/05 19:18:33 jakllsch Exp $

--- src/iop/lens.c.orig	2012-04-27 20:25:52.000000000 +0000
+++ src/iop/lens.c
@@ -842,7 +842,7 @@ static void parse_maker_model (
 {
   const gchar *sep;
 
-  while (txt [0] && isspace (txt [0]))
+  while (txt [0] && isspace ((unsigned char)txt [0]))
     txt++;
   sep = strchr (txt, ',');
   if (sep)
@@ -853,7 +853,7 @@ static void parse_maker_model (
     memcpy (make, txt, len);
     make [len] = 0;
 
-    while (*++sep && isspace (sep [0]))
+    while (*++sep && isspace ((unsigned char)sep [0]))
       ;
     len = strlen (sep);
     if (len > sz_model - 1)
