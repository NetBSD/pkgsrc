$NetBSD: patch-nss_cmd_signtool_util.c,v 1.1 2022/04/07 19:08:40 riastradh Exp $

Fix ctype(3) abuse: https://bugzilla.mozilla.org/show_bug.cgi?id=1246768

--- nss/cmd/signtool/util.c.orig	2022-03-03 10:18:53.000000000 +0000
+++ nss/cmd/signtool/util.c
@@ -835,14 +835,14 @@ chop(char *str)
         start = str;
 
         /* Nip leading whitespace */
-        while (isspace(*start)) {
+        while (isspace((unsigned char)*start)) {
             start++;
         }
 
         /* Nip trailing whitespace */
         if (*start) {
             end = start + strlen(start) - 1;
-            while (isspace(*end) && end > start) {
+            while (isspace((unsigned char)*end) && end > start) {
                 end--;
             }
             *(end + 1) = '\0';
