$NetBSD: patch-src_csvgrep.c,v 1.1 2016/07/20 23:15:52 cheusov Exp $

Properly use toupper(3).

--- src/csvgrep.c.orig	2008-07-27 17:45:20.000000000 +0000
+++ src/csvgrep.c
@@ -778,7 +778,7 @@ main (int argc, char *argv[])
       /* Upcase string for case insensitive fixed match*/
       char *ptr = pattern;
       while (*ptr)
-        *ptr = toupper(*ptr), ptr++;
+        *ptr = toupper((unsigned char)*ptr), ptr++;
     }
   } else if (match_type == PCRE) {
     #ifdef WITHOUT_PCRE
