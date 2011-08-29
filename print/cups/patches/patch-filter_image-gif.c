$NetBSD: patch-filter_image-gif.c,v 1.1.2.2 2011/08/29 08:15:07 tron Exp $

Use str3914.patch from STR #3914 to fix CVE-2011-3170

--- filter/image-gif.c.orig	2011-06-20 20:37:51.000000000 +0000
+++ filter/image-gif.c
@@ -648,11 +648,13 @@ gif_read_lzw(FILE *fp,			/* I - File to
 
     if (code == max_code)
     {
-      *sp++ = firstcode;
-      code  = oldcode;
+      if (sp < (stack + 8192))
+	*sp++ = firstcode;
+
+      code = oldcode;
     }
 
-    while (code >= clear_code)
+    while (code >= clear_code && sp < (stack + 8192))
     {
       *sp++ = table[1][code];
       if (code == table[0][code])
@@ -661,8 +663,10 @@ gif_read_lzw(FILE *fp,			/* I - File to
       code = table[0][code];
     }
 
-    *sp++ = firstcode = table[1][code];
-    code  = max_code;
+    if (sp < (stack + 8192))
+      *sp++ = firstcode = table[1][code];
+
+    code = max_code;
 
     if (code < 4096)
     {
