$NetBSD: patch-cli_src_cli.c,v 1.2 2024/08/06 21:10:48 riastradh Exp $

Avoid ctype(3) abuse.
https://github.com/gluster/glusterfs/issues/4397

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
