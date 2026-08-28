$NetBSD: patch-tools_cli_txt2mb.c,v 1.1 2026/08/28 01:52:12 tsutsui Exp $

Fix ctype abuse by casting to unsigned char

--- tools/cli/txt2mb.c.orig	2026-08-28 01:40:49.733711639 +0000
+++ tools/cli/txt2mb.c
@@ -361,13 +361,13 @@ int main(int argc, char *argv[])
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
