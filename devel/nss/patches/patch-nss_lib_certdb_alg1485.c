$NetBSD: patch-nss_lib_certdb_alg1485.c,v 1.1 2022/04/07 19:08:40 riastradh Exp $

Fix ctype(3) abuse: https://bugzilla.mozilla.org/show_bug.cgi?id=1246768

--- nss/lib/certdb/alg1485.c.orig	2022-03-03 10:18:53.000000000 +0000
+++ nss/lib/certdb/alg1485.c
@@ -402,7 +402,7 @@ ParseRFC1485AVA(PLArenaPool* arena, cons
     }
 
     /* is this a dotted decimal OID attribute type ? */
-    if (!PL_strncasecmp("oid.", tagBuf, 4) || isdigit(tagBuf[0])) {
+    if (!PL_strncasecmp("oid.", tagBuf, 4) || isdigit((unsigned char)tagBuf[0])) {
         rv = SEC_StringToOID(arena, &derOid, tagBuf, strlen(tagBuf));
         isDottedOid = (PRBool)(rv == SECSuccess);
     } else {
@@ -1332,7 +1332,7 @@ CERT_GetCertificateEmailAddress(CERTCert
     }
     if (rawEmailAddr) {
         for (i = 0; i <= (int)PORT_Strlen(rawEmailAddr); i++) {
-            rawEmailAddr[i] = tolower(rawEmailAddr[i]);
+            rawEmailAddr[i] = tolower((unsigned char)rawEmailAddr[i]);
         }
     }
 
@@ -1358,7 +1358,7 @@ appendStringToBuf(char* dest, char* src,
     if (dest && src && src[0] && *pRemaining > (len = PL_strlen(src))) {
         PRUint32 i;
         for (i = 0; i < len; ++i)
-            dest[i] = tolower(src[i]);
+            dest[i] = tolower((unsigned char)src[i]);
         dest[len] = 0;
         dest += len + 1;
         *pRemaining -= len + 1;
