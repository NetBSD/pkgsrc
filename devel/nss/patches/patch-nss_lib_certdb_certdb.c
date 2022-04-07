$NetBSD: patch-nss_lib_certdb_certdb.c,v 1.1 2022/04/07 19:08:40 riastradh Exp $

Fix ctype(3) abuse: https://bugzilla.mozilla.org/show_bug.cgi?id=1246768

--- nss/lib/certdb/certdb.c.orig	2022-03-03 10:18:53.000000000 +0000
+++ nss/lib/certdb/certdb.c
@@ -1313,7 +1313,7 @@ sec_lower_string(char *s)
     }
 
     while (*s) {
-        *s = PORT_Tolower(*s);
+        *s = PORT_Tolower((unsigned char)*s);
         s++;
     }
 
@@ -2304,7 +2304,7 @@ CERT_FixupEmailAddr(const char *emailAdd
 
     /* make it lower case */
     while (*str) {
-        *str = tolower(*str);
+        *str = tolower((unsigned char)*str);
         str++;
     }
 
