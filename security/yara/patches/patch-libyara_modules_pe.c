$NetBSD: patch-libyara_modules_pe.c,v 1.1 2017/11/15 18:22:22 he Exp $

Ensure we adhere to valid value domain for isxxxx() function/macro.

--- libyara/modules/pe.c.orig	2017-11-10 11:21:21.000000000 +0000
+++ libyara/modules/pe.c
@@ -1673,7 +1673,7 @@ define_function(imphash)
       // Lowercase the whole thing.
 
       for (i = 0; i < final_name_len; i++)
-        final_name[i] = tolower(final_name[i]);
+        final_name[i] = tolower((unsigned char)final_name[i]);
 
       yr_md5_update(&ctx, final_name, final_name_len);
 
