$NetBSD: patch-tnm_snmp_tnmSnmpRecv.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.
Avoid use of interp->result.

--- tnm/snmp/tnmSnmpRecv.c.orig	1999-05-17 16:15:33.000000000 +0000
+++ tnm/snmp/tnmSnmpRecv.c
@@ -669,16 +669,18 @@ DecodeMessage(interp, msg, pdu, packet, 
     int buflen = 0;
     u_int msglen = 0;
     u_char *p = packet;
+    char res[128];
     
     /*
      * Decode "Packet Header" header ( SEQUENCE 0x30 msglen )
      */
     
     if (*p++ != (ASN1_UNIVERSAL | ASN1_CONSTRUCTED | ASN1_SEQUENCE)) {
-	sprintf(interp->result,
+	sprintf(res,
 		"Message header: invalid value 0x%.2x; expecting 0x%.2x",
 		*--p, (ASN1_UNIVERSAL | ASN1_CONSTRUCTED | ASN1_SEQUENCE));
 	snmpStats.snmpInASNParseErrs++;
+	Tcl_SetResult(interp, res, TCL_VOLATILE);
 	return TCL_ERROR;
     }
     buflen += 1;
@@ -687,7 +689,8 @@ DecodeMessage(interp, msg, pdu, packet, 
     if (p == NULL) goto asn1Error;
     
     if ((buflen + msglen) != packetlen) {
-	interp->result = "invalid length field in message header";
+        Tcl_SetResult(interp, "invalid length field in message header",
+		      TCL_STATIC);
 	return TCL_ERROR;
     }
     
@@ -717,8 +720,9 @@ DecodeMessage(interp, msg, pdu, packet, 
 #endif
       default:
 	snmpStats.snmpInBadVersions++;
-	sprintf(interp->result,
+	sprintf(res,
 		"received packet with unknown SNMP version %d", version);
+	Tcl_SetResult(interp, res, TCL_VOLATILE);
         return TCL_ERROR;
     }
     
@@ -727,10 +731,11 @@ DecodeMessage(interp, msg, pdu, packet, 
      */
 
     if (*p != ASN1_OCTET_STRING) {
-        sprintf(interp->result,
+        sprintf(res,
 		"Parameter string: invalid value 0x%.2x; expecting 0x%.2x",
 		*p, ASN1_OCTET_STRING);
 	snmpStats.snmpInASNParseErrs++;
+	Tcl_SetResult(interp, res, TCL_VOLATILE);
 	return TCL_ERROR;
     }
     p = Tnm_BerDecOctetString(p, &buflen, ASN1_OCTET_STRING,
@@ -756,10 +761,11 @@ DecodeMessage(interp, msg, pdu, packet, 
     }
 
     if (buflen != msglen) {
-	sprintf(interp->result,
+	sprintf(res,
 		"Message sequence length (%d) differs from real length (%d).",
 		buflen, (int) msglen);
 	snmpStats.snmpInASNParseErrs++;
+	Tcl_SetResult(interp, res, TCL_VOLATILE);
 	return TCL_ERROR;
     }
 
@@ -986,6 +992,7 @@ DecodePDU(interp, pdu, packet, packetlen
     char *snmpTrapEnterprise = NULL;
 
     u_char tag;
+    char res[128];
 
     Tcl_DStringInit(&pdu->varbind);
 
@@ -1022,9 +1029,10 @@ DecodePDU(interp, pdu, packet, packetlen
 	pdu->type = TNM_SNMP_REPORT;
 	break;
       default:
-	sprintf(interp->result,
+	sprintf(res,
 		"Response-PDU: invalid tag 0x%.2x.", *--packet);
 	snmpStats.snmpInASNParseErrs++;
+	Tcl_SetResult(interp, res, TCL_VOLATILE);
 	return TCL_ERROR;
     }
     pdulen = 1;
@@ -1139,14 +1147,14 @@ DecodePDU(interp, pdu, packet, packetlen
 	Tcl_DStringAppendElement(&pdu->varbind, "OBJECT IDENTIFIER");
 	{
 #if 1
-	    char *tmp = Tnm_MibFormat("1.3.6.1.6.3.1.1.4.1.0", 0, toid);
+	    const char *tmp = Tnm_MibFormat("1.3.6.1.6.3.1.1.4.1.0", 0, toid);
 	    if (tmp) {
 		Tcl_DStringAppendElement(&pdu->varbind, tmp);
 	    } else {
 		Tcl_DStringAppendElement(&pdu->varbind, toid);
 	    }
 #else
-	    char *tmp = Tnm_MibGetName(toid, 0);
+	    const char *tmp = Tnm_MibGetName(toid, 0);
 	    if (tmp) {
 		Tcl_DStringAppendElement(&pdu->varbind, tmp);
 	    } else {
@@ -1201,10 +1209,11 @@ DecodePDU(interp, pdu, packet, packetlen
 	if (pdu->type == TNM_SNMPv1_TRAP) {
 	    goto trapError;
 	}
-	sprintf(interp->result,
+	sprintf(res,
 		"VarBindList: invalid tag 0x%.2x; expecting 0x%.2x",
 		*--packet, (ASN1_UNIVERSAL | ASN1_CONSTRUCTED | ASN1_SEQUENCE));
 	snmpStats.snmpInASNParseErrs++;
+	Tcl_SetResult(interp, res, TCL_VOLATILE);
 	return TCL_ERROR;
     }
     pdulen += 1;
@@ -1213,7 +1222,7 @@ DecodePDU(interp, pdu, packet, packetlen
     if (packet == NULL) goto asn1Error;
 	
     if ((pdulen + asnlen) != deflen) {
-	interp->result = "VarBindList: invalid length field";
+        Tcl_SetResult(interp, "VarBindList: invalid length field", TCL_STATIC);
 	snmpStats.snmpInASNParseErrs++;
 	return TCL_ERROR;
     }
@@ -1229,10 +1238,11 @@ DecodePDU(interp, pdu, packet, packetlen
 	 */
 	
 	if (*packet++ !=  (ASN1_UNIVERSAL | ASN1_CONSTRUCTED | ASN1_SEQUENCE)) {
-	    sprintf(interp->result,
+	    sprintf(res,
 		    "VarBind: invalid tag 0x%.2x; expecting 0x%.2x",
 		    *--packet, (ASN1_UNIVERSAL | ASN1_CONSTRUCTED | ASN1_SEQUENCE));
 	    snmpStats.snmpInASNParseErrs++;
+	    Tcl_SetResult(interp, res, TCL_VOLATILE);
 	    return TCL_ERROR;
 	}
 	pdulen += 1;
@@ -1316,7 +1326,7 @@ DecodePDU(interp, pdu, packet, packetlen
 	  case ASN1_INTEGER:
             packet = Tnm_BerDecInt(packet, &pdulen, *packet, &int_val);
             if (packet == NULL) goto asn1Error;
-	    {   char *tmp;
+	    {   const char *tmp;
 		sprintf(buf, "%d", int_val);
 		tmp = Tnm_MibFormat(vboid, 0, buf);
 		if (tmp) {
@@ -1367,7 +1377,7 @@ DecodePDU(interp, pdu, packet, packetlen
             if (packet == NULL) goto asn1Error;
 #if 1
 	    {   char *soid = Tnm_OidToStr(oid, oidlen);
-		char *tmp = Tnm_MibFormat(vboid, 0, soid);
+		const char *tmp = Tnm_MibFormat(vboid, 0, soid);
 		if (tmp) {
 		    Tcl_DStringAppendElement(&pdu->varbind, tmp);
 		} else {
@@ -1396,7 +1406,7 @@ DecodePDU(interp, pdu, packet, packetlen
             packet = Tnm_BerDecOctetString(packet, &pdulen, tag, 
 					   (char **) &freeme, &int_val);
             if (packet == NULL) goto asn1Error;
-	    {   char *tmp;
+	    {   const char *tmp;
 		static char *hex = NULL;
 		static int hexLen = 0;
 		if (hexLen < int_val * 5 + 1) {
@@ -1418,8 +1428,9 @@ DecodePDU(interp, pdu, packet, packetlen
 	    }
             break;
 	  default:
-            sprintf(interp->result, "unknown asn1 type 0x%.2x", *packet);
+            sprintf(res, "unknown asn1 type 0x%.2x", *packet);
 	    snmpStats.snmpInASNParseErrs++;
+	    Tcl_SetResult(interp, res, TCL_VOLATILE);
             return TCL_ERROR;
 	}
 	
@@ -1444,10 +1455,11 @@ DecodePDU(interp, pdu, packet, packetlen
     *packetlen += pdulen;
     
     if (pdulen != deflen) {
-	sprintf(interp->result,
+	sprintf(res,
 		"PDU sequence length (%d) differs from real length (%d).",
 		pdulen, (int) deflen);
 	snmpStats.snmpInASNParseErrs++;
+	Tcl_SetResult(interp, res, TCL_VOLATILE);
 	return TCL_ERROR;
     }
 
