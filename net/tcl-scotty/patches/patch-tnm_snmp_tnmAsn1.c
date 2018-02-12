$NetBSD: patch-tnm_snmp_tnmAsn1.c,v 1.3 2018/02/12 14:52:14 he Exp $

Constify.
Provide some robustness against mis-coded OIDs.

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
@@ -939,12 +945,16 @@ Tnm_BerDecOID(packet, packetlen, oid, oi
 
     while (asnlen > 0) {
 	memset((char *) op, 0, sizeof(oid));
-	while (*packet > 0x7F) {
+	while (*packet > 0x7F && asnlen > 0) {
 	    /* hansb@aie.nl (Hans Bayle) had problems with SCO. */
 	    *op = ( *op << 7 ) + ( *packet++ & 0x7F );
 	    asnlen     -= 1;
 	    *packetlen += 1;
 	}
+	if (asnlen == 0) {
+	    strcpy(error, "OID decode: miscoded, ran out of data");
+	    return NULL;
+	}
 
 	*op = ( *op << 7 ) + ( *packet++ );
 	op         += 1;
