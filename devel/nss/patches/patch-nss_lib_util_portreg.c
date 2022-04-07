$NetBSD: patch-nss_lib_util_portreg.c,v 1.1 2022/04/07 19:08:40 riastradh Exp $

Fix ctype(3) abuse: https://bugzilla.mozilla.org/show_bug.cgi?id=1246768

--- nss/lib/util/portreg.c.orig	2022-03-03 10:18:53.000000000 +0000
+++ nss/lib/util/portreg.c
@@ -275,7 +275,7 @@ _shexp_match(const char *str, const char
                         if (exp[y] == '\\')
                             ++y;
                         if (case_insensitive) {
-                            matched |= (toupper(str[x]) == toupper(exp[y]));
+                            matched |= (toupper((unsigned char)str[x]) == toupper((unsigned char)exp[y]));
                         } else {
                             matched |= (str[x] == exp[y]);
                         }
@@ -299,7 +299,7 @@ _shexp_match(const char *str, const char
             /* fall through */
             default:
                 if (case_insensitive) {
-                    if (toupper(str[x]) != toupper(exp[y]))
+                    if (toupper((unsigned char)str[x]) != toupper((unsigned char)exp[y]))
                         return NOMATCH;
                 } else {
                     if (str[x] != exp[y])
