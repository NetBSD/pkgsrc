$NetBSD: patch-tnm_snmp_tnmSnmpUtil.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.
Avoid use of interp->result.

--- tnm/snmp/tnmSnmpUtil.c.orig	1998-04-23 11:18:13.000000000 +0000
+++ tnm/snmp/tnmSnmpUtil.c
@@ -569,16 +569,17 @@ Tnm_SnmpEvalCallback(interp, session, pd
     Tcl_Interp *interp;
     SNMP_Session *session;
     SNMP_PDU *pdu;
-    char *cmd;
-    char *instance;
-    char *oid;
-    char *value;
+    const char *cmd;
+    const char *instance;
+    const char *oid;
+    const char *value;
     char *last;
 {
     char buf[20];
     int	code;
     Tcl_DString tclCmd;
-    char *startPtr, *scanPtr, *name;
+    char *name;
+    const char *startPtr, *scanPtr;
 
     Tcl_DStringInit(&tclCmd);
     startPtr = cmd;
@@ -676,7 +677,7 @@ Tnm_SnmpEvalCallback(interp, session, pd
      */
 
     if (code == TCL_ERROR && oid == NULL) {
-	char *errorMsg = ckstrdup(interp->result);
+        char *errorMsg = ckstrdup(Tcl_GetStringResult(interp));
 	Tcl_AddErrorInfo(interp, "\n    (snmp callback)");
 	Tcl_BackgroundError(interp);
 	Tcl_SetResult(interp, errorMsg, TCL_DYNAMIC);
@@ -752,7 +753,7 @@ Tnm_SnmpDumpPDU(interp, pdu)
     if (hexdump) {
 
         int i, code, argc;
-	char **argv;
+	const char **argv;
 	char *name, *status;
 
 	name = TnmGetTableValue(tnmSnmpPDUTable, pdu->type);
@@ -1234,12 +1235,12 @@ TnmSnmpGetRequestId()
 int
 Tnm_SnmpSplitVBList(interp, list, varBindSizePtr, varBindPtrPtr)
     Tcl_Interp *interp;
-    char *list;
+    const char *list;
     int *varBindSizePtr;
     SNMP_VarBind **varBindPtrPtr;
 {
     int code, vblc, i;
-    char **vblv;
+    const char **vblv;
     int varBindSize;
     SNMP_VarBind *varBindPtr;
 
@@ -1260,7 +1261,7 @@ Tnm_SnmpSplitVBList(interp, list, varBin
 
     for (i = 0; i < varBindSize; i++) {
         int vbc;
-        char **vbv;
+        const char **vbv;
         code = Tcl_SplitList(interp, vblv[i], &vbc, &vbv);
 	if (code != TCL_OK) {
 	    Tnm_SnmpFreeVBList(varBindSize, varBindPtr);
@@ -1346,7 +1347,7 @@ Tnm_SnmpMergeVBList(varBindSize, varBind
 void
 Tnm_SnmpFreeVBList(varBindSize, varBindPtr)
     int varBindSize;
-    SNMP_VarBind *varBindPtr;
+    const SNMP_VarBind *varBindPtr;
 {
     int i;
     
@@ -1409,7 +1410,7 @@ Tnm_SnmpSysUpTime()
 
 void
 Tnm_SnmpBinToHex(s, n, d)
-    char *s;
+    const char *s;
     int n;
     char *d;
 {
@@ -1446,7 +1447,8 @@ Tnm_SnmpBinToHex(s, n, d)
 
 int
 Tnm_SnmpHexToBin(s, d, n)
-    char *s, *d;
+    const char *s;
+    char *d;
     int *n;
 {
     int v;
