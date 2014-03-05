$NetBSD: patch-tnm_snmp_tnmAsn1.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.

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
