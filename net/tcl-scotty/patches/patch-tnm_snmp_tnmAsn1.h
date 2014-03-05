$NetBSD: patch-tnm_snmp_tnmAsn1.h,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.

--- tnm/snmp/tnmAsn1.h.orig	2014-03-05 10:06:28.000000000 +0000
+++ tnm/snmp/tnmAsn1.h
@@ -85,19 +85,19 @@ typedef u_int Tnm_Oid;
  */
 
 EXTERN char*
-Tnm_OidToStr		_ANSI_ARGS_((Tnm_Oid *oid, int len));
+Tnm_OidToStr		_ANSI_ARGS_((const Tnm_Oid *oid, int len));
 
 EXTERN Tnm_Oid*
-Tnm_StrToOid		_ANSI_ARGS_((char *str, int *len));
+Tnm_StrToOid		_ANSI_ARGS_((const char *str, int *len));
 
 EXTERN Tnm_Oid*
 Tnm_OidDup		_ANSI_ARGS_((int *buflen, Tnm_Oid *oid, int oidLen));
 
 EXTERN int
-Tnm_IsOid		_ANSI_ARGS_((char *str));
+Tnm_IsOid		_ANSI_ARGS_((const char *str));
 
 EXTERN char*
-Tnm_HexToOid		_ANSI_ARGS_((char *str));
+Tnm_HexToOid		_ANSI_ARGS_((const char *str));
 
 /*
  *----------------------------------------------------------------
