$NetBSD: patch-nss_lib_softoken_legacydb_lowcert.c,v 1.1 2022/04/07 19:08:40 riastradh Exp $

Fix ctype(3) abuse: https://bugzilla.mozilla.org/show_bug.cgi?id=1246768

--- nss/lib/softoken/legacydb/lowcert.c.orig	2022-03-03 10:18:53.000000000 +0000
+++ nss/lib/softoken/legacydb/lowcert.c
@@ -615,7 +615,7 @@ nsslowcert_GetCertificateEmailAddress(NS
     /* make it lower case */
     str = emailAddr;
     while (str && *str) {
-        *str = tolower(*str);
+        *str = tolower((unsigned char)*str);
         str++;
     }
     return emailAddr;
@@ -717,7 +717,7 @@ nsslowcert_FixupEmailAddr(char *emailAdd
 
     /* make it lower case */
     while (*str) {
-        *str = tolower(*str);
+        *str = tolower((unsigned char)*str);
         str++;
     }
 
