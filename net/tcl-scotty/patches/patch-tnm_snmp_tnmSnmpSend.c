$NetBSD: patch-tnm_snmp_tnmSnmpSend.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.
Avoid use of interp->result.

--- tnm/snmp/tnmSnmpSend.c.orig	1999-03-23 17:15:14.000000000 +0000
+++ tnm/snmp/tnmSnmpSend.c
@@ -67,6 +67,7 @@ Tnm_SnmpEncode(interp, session, pdu, pro
 {
     int	retry = 0, packetlen = 0, rc = 0;
     u_char packet[TNM_SNMP_MAXSIZE];
+    char res[20];
 
     memset((char *) packet, 0, sizeof(packet));
     packetlen = 0;
@@ -166,7 +167,8 @@ Tnm_SnmpEncode(interp, session, pdu, pro
 	rPtr = Tnm_SnmpCreateRequest(pdu->request_id, packet, packetlen,
 				     proc, clientData, interp);
 	Tnm_SnmpQueueRequest(session, rPtr);
-	sprintf(interp->result, "%d", (int) pdu->request_id);
+	sprintf(res, "%d", (int) pdu->request_id);
+	Tcl_SetResult(interp, res, TCL_VOLATILE);
 	return TCL_OK;
     }
     
@@ -230,7 +232,8 @@ Tnm_SnmpEncode(interp, session, pdu, pro
 	    
 	    if (rc == TCL_CONTINUE) {
 		if (hexdump) {
-		    fprintf(stderr, "%s\n", interp->result);
+		    fprintf(stderr, "%s\n",
+			    Tcl_GetStringResult(interp));
 		}
 		continue;
 	    }
@@ -320,7 +323,7 @@ EncodeMessage(interp, session, pdu, pack
 
     p = EncodePDU(interp, session, pdu, p, packetlen);
     if (p == NULL) {
-	if (*interp->result == '\0') {
+        if (*Tcl_GetStringResult(interp) == '\0') {
 	    Tcl_SetResult(interp, Tnm_BerError(), TCL_STATIC);
 	}
 	return TCL_ERROR;
@@ -577,10 +580,10 @@ EncodePDU(interp, session, pdu, packet, 
     u_char *PDU_len = NULL, *VarBind_len = NULL, *VarBindList_len = NULL;
     
     int i, vblc, vbc;
-    char **vblv, **vbv;
-
+    const char **vblv, **vbv;
     Tnm_Oid *oid;
     int oidlen;
+    char res[64];
 
     /*
      * encode pdu type ( tag: [pdu_type] IMPLICIT PDU )
@@ -709,7 +712,7 @@ EncodePDU(interp, session, pdu, packet, 
     
     for (i = 0; i < vblc; i++) {
 	
-	char *value;
+        const char *value;
 	int asn1_type = ASN1_OTHER;
 	
 	/*
@@ -742,7 +745,7 @@ EncodePDU(interp, session, pdu, packet, 
 	if (Tnm_IsOid(vbv[0])) {
 	    oid = Tnm_StrToOid(vbv[0], &oidlen);
 	} else {
-	    char *tmp = Tnm_MibGetOid(vbv[0], 0);
+	    const char *tmp = Tnm_MibGetOid(vbv[0], 0);
 	    if (! tmp) {
 		Tcl_ResetResult(interp);
 		Tcl_AppendResult(interp, "invalid object identifier \"",
@@ -835,7 +838,7 @@ EncodePDU(interp, session, pdu, packet, 
 		{   int int_val, rc;
 		    rc = Tcl_GetInt(interp, value, &int_val);
 		    if (rc != TCL_OK) {
-			char *tmp = Tnm_MibScan(vbv[0], 0, value);
+			const char *tmp = Tnm_MibScan(vbv[0], 0, value);
 			if (tmp && *tmp) {
 			    Tcl_ResetResult(interp);
 			    rc = Tcl_GetInt(interp, tmp, &int_val);
@@ -851,7 +854,7 @@ EncodePDU(interp, session, pdu, packet, 
 		    if (sizeof(int) >= 8) {
 			rc = Tcl_GetInt(interp, value, &int_val);
 			if (rc != TCL_OK) {
-			    char *tmp = Tnm_MibScan(vbv[0], 0, value);
+			    const char *tmp = Tnm_MibScan(vbv[0], 0, value);
 			    if (tmp && *tmp) {
 				Tcl_ResetResult(interp);
 				rc = Tcl_GetInt(interp, tmp, &int_val);
@@ -910,11 +913,11 @@ EncodePDU(interp, session, pdu, packet, 
 		}
 		break;
 	      case ASN1_OCTET_STRING:
-		{   char *hex = value;
+		{   const char *hex = value;
 		    int len;
 		    static char *bin = NULL;
 		    static int binLen = 0;
-		    char *scan = Tnm_MibScan(vbv[0], 0, value);
+		    const char *scan = Tnm_MibScan(vbv[0], 0, value);
 		    if (scan) hex = scan;
 		    if (*hex) {
 		        len = strlen(hex);
@@ -937,7 +940,7 @@ EncodePDU(interp, session, pdu, packet, 
 		}
 		break;
 	      case ASN1_OPAQUE:
-	        {   char *hex = value;
+	        {   const char *hex = value;
 		    int len;
 		    static char *bin = NULL;
 		    static int binLen = 0;
@@ -962,7 +965,7 @@ EncodePDU(interp, session, pdu, packet, 
 		break;
 	      case ASN1_OBJECT_IDENTIFIER:
 		if (! Tnm_IsOid(value)) {
-		    char *tmp = Tnm_MibGetOid(value, 0);
+		    const char *tmp = Tnm_MibGetOid(value, 0);
 		    if (!tmp) {
 			Tcl_AppendResult(interp, 
 					 "illegal object identifier \"",
@@ -982,8 +985,9 @@ EncodePDU(interp, session, pdu, packet, 
 		packet = Tnm_BerEncNull(packet, packetlen, asn1_type);
 		break;
 	      default:
-		sprintf(interp->result, "unknown asn1 type 0x%.2x",
+		sprintf(res, "unknown asn1 type 0x%.2x",
 			asn1_type);
+		Tcl_SetResult(interp, res, TCL_VOLATILE);
 		return NULL;
 	    }
 	} else {
