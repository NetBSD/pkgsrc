$NetBSD: patch-tnm_snmp_tnmSnmpAgent.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.
Avoid use of interp->result.

--- tnm/snmp/tnmSnmpAgent.c.orig	1998-05-19 13:13:53.000000000 +0000
+++ tnm/snmp/tnmSnmpAgent.c
@@ -52,18 +52,21 @@ CacheHit		_ANSI_ARGS_((SNMP_Session *ses
 static char*
 TraceSysUpTime		_ANSI_ARGS_((ClientData clientData,
 				     Tcl_Interp *interp,
-				     char *name1, char *name2, int flags));
+				     const char *name1, const char *name2,
+				     int flags));
 #ifdef TNM_SNMPv2U
 static char*
 TraceAgentTime		_ANSI_ARGS_((ClientData clientData,
 				     Tcl_Interp *interp,
-				     char *name1, char *name2, int flags));
+				     const char *name1, const char *name2,
+				     int flags));
 #endif
 
 static char*
 TraceUnsignedInt	_ANSI_ARGS_((ClientData clientData,
 				     Tcl_Interp *interp,
-				     char *name1, char *name2, int flags));
+				     const char *name1, const char *name2,
+				     int flags));
 static TnmSnmpNode*
 FindInstance		_ANSI_ARGS_((SNMP_Session *session,
 				     Tnm_Oid *oid, int oidlen));
@@ -312,8 +315,8 @@ static char*
 TraceSysUpTime(clientData, interp, name1, name2, flags)
     ClientData clientData;
     Tcl_Interp *interp;
-    char *name1;
-    char *name2;
+    const char *name1;
+    const char *name2;
     int flags;
 {
     char buf[20];
@@ -344,8 +347,8 @@ static char*
 TraceAgentTime(clientData, interp, name1, name2, flags)
     ClientData clientData;
     Tcl_Interp *interp;
-    char *name1;
-    char *name2;
+    const char *name1;
+    const char *name2;
     int flags;
 {
     char buf[20];
@@ -377,8 +380,8 @@ static char*
 TraceUnsignedInt(clientData, interp, name1, name2, flags)
     ClientData clientData;
     Tcl_Interp *interp;
-    char *name1;
-    char *name2;
+    const char *name1;
+    const char *name2;
     int flags;
 {
     char buf[20];
@@ -410,12 +413,15 @@ Tnm_SnmpAgentInit(interp, session)
     SNMP_Session *session;
 {
     static int done = 0;
-    char tclvar[80], buffer[255], *value;
+    char tclvar[80], buffer[255];
+    const char *value;
     struct StatReg *p;
 
     if (Tnm_SnmpAgentOpen(session->agentInterp, session) != TCL_OK) {
 	if (interp != session->agentInterp) {
-	    Tcl_SetResult(interp, session->agentInterp->result, TCL_STATIC);
+	  Tcl_SetResult(interp,
+			(char*)Tcl_GetStringResult(session->agentInterp),
+			TCL_VOLATILE);
 	}
 	return TCL_ERROR;
     }
@@ -618,7 +624,7 @@ GetRequest(interp, session, request, res
 
     for (i = 0; i < inVarBindSize; i++) {
 
-	char *value, *syntax;
+	const char *value, *syntax;
 
 	oid = Tnm_StrToOid(inVarBindPtr[i].soid, &oidlen);
 	if (request->type == TNM_SNMP_GETNEXT 
@@ -689,7 +695,7 @@ GetRequest(interp, session, request, res
 
       varBindTclError:
 	response->error_status = TnmGetTableKey(tnmSnmpErrorTable, 
-						interp->result);
+						Tcl_GetStringResult(interp));
 	if (response->error_status < 0) {
 	    response->error_status = TNM_SNMP_GENERR;
 	}
@@ -755,7 +761,7 @@ SetRequest(interp, session, request, res
 
     for (i = 0; i < inVarBindSize; i++) {
 
-	char *value, *syntax;
+	const char *value, *syntax;
 	int setAlreadyDone = 0;
 	varsToRollback = i;
 	
@@ -859,7 +865,7 @@ SetRequest(interp, session, request, res
 
       varBindTclError:
 	response->error_status = TnmGetTableKey(tnmSnmpErrorTable, 
-						interp->result);
+						Tcl_GetStringResult(interp));
 	if (response->error_status < 0) {
 	    response->error_status = TNM_SNMP_GENERR;
 	}
@@ -902,8 +908,9 @@ SetRequest(interp, session, request, res
 	    }
 
 	    if (code != TCL_OK) {
-		response->error_status = TnmGetTableKey(tnmSnmpErrorTable, 
-							interp->result);
+		response->error_status =
+		  TnmGetTableKey(tnmSnmpErrorTable, 
+				 Tcl_GetStringResult(interp));
 		if (response->error_status < 0) {
 		    response->error_status = TNM_SNMP_GENERR;
 		}
