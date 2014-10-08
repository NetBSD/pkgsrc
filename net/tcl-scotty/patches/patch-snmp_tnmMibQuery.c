$NetBSD: patch-snmp_tnmMibQuery.c,v 1.1 2014/10/08 15:50:18 he Exp $

Treat DISPLAY-HINT with 't' (UTF-8 string) the same as 'a' (ASCII string).

--- ./tnm/snmp/tnmMibQuery.c.orig	1999-12-09 15:17:00.000000000 +0000
+++ ./tnm/snmp/tnmMibQuery.c
@@ -705,7 +705,7 @@ FormatOctetTC(val, fmt)
 	}
 
 	/* scan format: */
-	if (*fmt == 'a') {
+	if (*fmt == 'a' || *fmt == 't') {
 
 	    while (*val && pfx > 0) {
 	        char c = *val++ & 0xff;
