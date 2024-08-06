$NetBSD: patch-cli_src_cli.c,v 1.1 2024/08/06 18:51:19 riastradh Exp $

Avoid ctype(3) abuse.

--- cli/src/cli.c.orig	2020-09-16 18:40:32.173503540 +0000
+++ cli/src/cli.c
@@ -349,7 +349,7 @@ is_valid_int(char *str)
 
     /* Check for non-digit chars in the rest of the string */
     while (*str) {
-        if (!isdigit(*str))
+        if (!isdigit((unsigned char)*str))
             return _gf_false;
         else
             ++str;
