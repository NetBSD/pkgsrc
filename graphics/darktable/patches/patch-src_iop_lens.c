$NetBSD: patch-src_iop_lens.c,v 1.2 2012/12/08 00:15:26 jakllsch Exp $

--- src/iop/lens.c.orig	2012-11-23 23:23:21.000000000 +0000
+++ src/iop/lens.c
@@ -1106,7 +1106,7 @@ static void parse_maker_model (
 {
   const gchar *sep;
 
-  while (txt [0] && isspace (txt [0]))
+  while (txt [0] && isspace ((unsigned char)txt [0]))
     txt++;
   sep = strchr (txt, ',');
   if (sep)
@@ -1117,7 +1117,7 @@ static void parse_maker_model (
     memcpy (make, txt, len);
     make [len] = 0;
 
-    while (*++sep && isspace (sep [0]))
+    while (*++sep && isspace ((unsigned char)sep [0]))
       ;
     len = strlen (sep);
     if (len > sz_model - 1)
