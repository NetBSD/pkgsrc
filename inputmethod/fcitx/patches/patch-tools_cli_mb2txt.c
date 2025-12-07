$NetBSD: patch-tools_cli_mb2txt.c,v 1.1 2025/12/07 03:00:56 maya Exp $

Fix ctype abuse by casting to unsigned char

--- tools/cli/mb2txt.c.orig	2025-12-06 22:37:28.453047847 +0000
+++ tools/cli/mb2txt.c
@@ -85,7 +85,7 @@ char guessValidChar(char prefer, const c
         return prefer;
     unsigned char c = 0;
     for (c = 0; c <= 127; c ++) {
-        if (ispunct(c) || isalnum(c)) {
+        if (ispunct((unsigned char) c) || isalnum((unsigned char) c)) {
             if (!strchr(invalid, c))
                 break;
         }
