$NetBSD: patch-tnm_snmp_tnmAsn1.c,v 1.2 2018/02/02 13:55:29 he Exp $

Constify.
Provide minimal robustness against mis-coded OIDs.

--- tnm/snmp/tnmAsn1.c.orig	1996-07-29 21:33:44.000000000 +0000
+++ tnm/snmp/tnmAsn1.c
@@ -107,7 +107,7 @@ Tnm_OidDup(buflen, oid, oidLen)
 
 char*
 Tnm_OidToStr(oid, oidLen)
-    Tnm_Oid *oid;
+    const Tnm_Oid *oid;
     int oidLen;
 {
     int	 i;
@@ -157,7 +157,7 @@ Tnm_OidToStr(oid, oidLen)
 
 Tnm_Oid*
 Tnm_StrToOid(str, len)
-    char *str;
+    const char *str;
     int *len;
 {
     static Tnm_Oid oid[TNM_OIDMAXLEN];
@@ -204,9 +204,9 @@ Tnm_StrToOid(str, len)
 
 int
 Tnm_IsOid(str)
-    char *str;
+    const char *str;
 {
-    char *cp;
+    const char *cp;
 
     for (cp = str; *cp != '\0'; cp++) {
         if (!isdigit(*cp) && *cp != '.') return 0;
@@ -236,10 +236,11 @@ Tnm_IsOid(str)
 
 char*
 Tnm_HexToOid(str)
-    char *str;
+    const char *str;
 {
     static char expstr[TNM_OIDMAXLEN * 8];
-    char *p, *s;
+    const char *p;
+    char *s;
     int convert = 0;
 
     if (! str) return NULL;
@@ -914,6 +915,11 @@ Tnm_BerDecOID(packet, packetlen, oid, oi
 	strcpy(error, "OBJECT IDENTIFIER of length 0");
 	return NULL;
     }
+    if (asnlen > TNM_OIDMAXLEN) {
+	sprintf(error, "OBJECT IDENTIFIER too long: %d, max is %d",
+		asnlen, TNM_OIDMAXLEN);
+	return NULL;
+    }
     
     if (asnlen == 1 && (*packet % 40 == *packet)) {
 	*oid       = *packet++;
