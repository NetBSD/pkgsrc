$NetBSD: patch-src_module_quickphrase_quickphrase.c,v 1.1 2025/12/07 03:00:55 maya Exp $

Fix ctype abuse by casting to unsigned char

--- src/module/quickphrase/quickphrase.c.orig	2025-12-06 22:31:33.481721537 +0000
+++ src/module/quickphrase/quickphrase.c
@@ -263,13 +263,13 @@ void LoadQuickPhraseFromFile(QuickPhrase
         buf1 = fcitx_utils_trim(buf);
         char *p = buf1;
 
-        while (*p && !isspace(*p))
+        while (*p && !isspace((unsigned char) *p))
             p ++;
 
         if (*p == '\0')
             continue;
 
-        while (isspace(*p)) {
+        while (isspace((unsigned char) *p)) {
             *p = '\0';
             p ++;
         }
