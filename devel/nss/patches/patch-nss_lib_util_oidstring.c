$NetBSD: patch-nss_lib_util_oidstring.c,v 1.1 2022/04/07 19:08:40 riastradh Exp $

Fix ctype(3) abuse: https://bugzilla.mozilla.org/show_bug.cgi?id=1246768

--- nss/lib/util/oidstring.c.orig	2022-03-03 10:18:53.000000000 +0000
+++ nss/lib/util/oidstring.c
@@ -50,7 +50,7 @@ SEC_StringToOID(PLArenaPool *pool, SECIt
     }
     do {
         PRUint32 decimal = 0;
-        while (len > 0 && isdigit(*from)) {
+        while (len > 0 && isdigit((unsigned char)*from)) {
             PRUint32 addend = (*from++ - '0');
             --len;
             if (decimal > max_decimal) /* overflow */
