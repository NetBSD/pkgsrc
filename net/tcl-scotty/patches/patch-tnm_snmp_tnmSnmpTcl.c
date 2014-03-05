$NetBSD: patch-tnm_snmp_tnmSnmpTcl.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.
Avoid use of interp->result.

--- tnm/snmp/tnmSnmpTcl.c.orig	2000-08-11 16:25:20.000000000 +0000
+++ tnm/snmp/tnmSnmpTcl.c
@@ -36,12 +36,12 @@ static Tcl_HashTable aliasTable;
 static void
 EvalCmdProc	_ANSI_ARGS_((SNMP_Session *session, SNMP_PDU *pdu, 
 			     ClientData clientData));
-static char *
+static const char *
 GetOption	_ANSI_ARGS_((Tcl_Interp *interp, ClientData object, 
 			     int option));
 static int
-SetOption	_ANSI_ARGS_((Tcl_Interp *interp, ClientData object, 
-			     int option, char *value));
+SetOption	_ANSI_ARGS_((Tcl_Interp *interp, ClientData object,
+			     int option, const char *value));
 static int
 Configured	_ANSI_ARGS_((Tcl_Interp *interp, SNMP_Session *session));
 
@@ -50,37 +50,37 @@ DeleteAgentInterp _ANSI_ARGS_((ClientDat
 
 static int
 SnmpCmd		_ANSI_ARGS_((ClientData	clientData, Tcl_Interp *interp,
-			     int argc, char **argv));
+			     int argc, const char **argv));
 static int
 SessionCmd	_ANSI_ARGS_((ClientData	clientData, Tcl_Interp *interp,
-			     int argc, char **argv));
+			     int argc, const char **argv));
 static int
 WaitSession	_ANSI_ARGS_((Tcl_Interp *interp, SNMP_Session *session, 
-			     char *id));
+			     const char *id));
 static void
 DestroySession	_ANSI_ARGS_((ClientData clientdata));
 
 static int
 Request		_ANSI_ARGS_((Tcl_Interp *interp, SNMP_Session *session,
-			     int pdu_type, int argc, char **argv));
+			     int pdu_type, int argc, const char **argv));
 static int
 Walk		_ANSI_ARGS_((Tcl_Interp *interp, SNMP_Session *session,
-			     int argc, char **argv));
+			     int argc, const char **argv));
 static int
 ExpandTable	_ANSI_ARGS_((Tcl_Interp *interp, 
-			     char *tList, Tcl_DString *dst));
+			     const char *tList, Tcl_DString *dst));
 static int
 ExpandScalars	_ANSI_ARGS_((Tcl_Interp *interp, 
-			     char *sList, Tcl_DString *dst));
+			     const char *sList, Tcl_DString *dst));
 static int
 Table		_ANSI_ARGS_((Tcl_Interp *interp, SNMP_Session *session,
-			     int argc, char **argv));
+			     int argc, const char **argv));
 static int
 Scalars		_ANSI_ARGS_((Tcl_Interp *interp, SNMP_Session *session,
-			     int argc, char **argv));
+			     int argc, const char **argv));
 static void
-ScalarSetVar	_ANSI_ARGS_((Tcl_Interp *interp, char *vbl,
-			     char *varName, Tcl_DString *result));
+ScalarSetVar	_ANSI_ARGS_((Tcl_Interp *interp, const char *vbl,
+			     const char *varName, Tcl_DString *result));
 
 /*
  * The options used to configure snmp session objects.
@@ -197,7 +197,7 @@ EvalCmdProc(session, pdu, clientData)
  *----------------------------------------------------------------------
  */
 
-static char *
+static const char *
 GetOption(interp, object, option)
     Tcl_Interp *interp;
     ClientData object;
@@ -280,7 +280,7 @@ GetOption(interp, object, option)
 	Tcl_ResetResult(interp);
 	code = Tcl_GetInterpPath(interp, session->agentInterp);
 	if (code == TCL_OK) {
-	    return interp->result;
+	    return Tcl_GetStringResult(interp);
 	}
 	return "";
     case TNM_SNMP_OPT_TIMEOUT:
@@ -335,7 +335,7 @@ SetOption(interp, object, option, value)
     Tcl_Interp *interp;
     ClientData object;
     int option;
-    char *value;
+    const char *value;
 {
     SNMP_Session *session = (SNMP_Session *) object;
     int num;
@@ -451,7 +451,7 @@ SetOption(interp, object, option, value)
 	{
 	    Tcl_HashEntry *entryPtr;
 	    int i, largc, code;
-	    char **largv, **argv;
+	    const char **largv, **argv;
 	    char *alias;
 	    entryPtr = Tcl_FindHashEntry(&aliasTable, value);
 	    if (! entryPtr) {
@@ -468,7 +468,7 @@ SetOption(interp, object, option, value)
 		return TCL_ERROR;
 	    }
 	    Tcl_SetHashValue(entryPtr, NULL);
-	    argv = (char **) ckalloc((largc + 3) * sizeof(char *));
+	    argv = (const char **) ckalloc((largc + 3) * sizeof(char *));
 	    argv[0] = session->name;
 	    argv[1] = "configure";
 	    for (i = 0; i < largc; i++) {
@@ -531,7 +531,7 @@ Configured(interp, session)
     Tcl_Interp *interp;
     SNMP_Session *session;
 {
-    char *name = Tcl_GetCommandName(interp, session->token);
+    const char *name = Tcl_GetCommandName(interp, session->token);
 
     if (! session->version) {
         Tcl_AppendResult(interp, "session \"", name, 
@@ -660,7 +660,7 @@ SnmpCmd(clientData, interp, argc, argv)
     ClientData clientData;
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     static char mibCmd[20];
     SNMP_Session *session;
@@ -858,7 +858,7 @@ SessionCmd(clientData, interp, argc, arg
     ClientData clientData;
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     SNMP_Session *session = (SNMP_Session *) clientData;
     int code;
@@ -953,7 +953,7 @@ SessionCmd(clientData, interp, argc, arg
 
     } else if (strcmp(argv[1], "inform") == 0) {
 	if (session->version == TNM_SNMPv1) {
-	    char *name = Tcl_GetCommandName(interp, session->token);
+	    const char *name = Tcl_GetCommandName(interp, session->token);
 	    Tcl_AppendResult(interp, "inform option not allowed on ",
 			     "SNMPv1 session \"", name, "\"", (char *) NULL);
 	    return TCL_ERROR;
@@ -1023,7 +1023,7 @@ SessionCmd(clientData, interp, argc, arg
 	    }
 	} else {
 
-	    char *oidstr = Tnm_MibGetOid(argv[2], 0);
+	    const char *oidstr = Tnm_MibGetOid(argv[2], 0);
 	    Tnm_Oid *oid;
 	    int code, oidlen;
 	    
@@ -1069,7 +1069,7 @@ SessionCmd(clientData, interp, argc, arg
 	}
 	
         if (! session->agentInterp) {
-	    char *name = Tcl_GetCommandName(interp, session->token);
+	    const char *name = Tcl_GetCommandName(interp, session->token);
 	    Tcl_AppendResult(interp, "invalid agent session \"", 
 			     name, "\"", (char *) NULL);
 	    return TCL_ERROR;
@@ -1078,7 +1078,8 @@ SessionCmd(clientData, interp, argc, arg
 				  (argc > 4) ? argv[4] : "");
 	if (code != TCL_OK) {
 	    if (interp != session->agentInterp) {
-		Tcl_SetResult(interp, session->agentInterp->result, 
+	        Tcl_SetResult(interp,
+			      (char*)Tcl_GetStringResult(session->agentInterp), 
 			      TCL_VOLATILE);
 		Tcl_ResetResult(session->agentInterp);
 	    }
@@ -1116,17 +1117,17 @@ static int
 WaitSession(interp, session, request)
     Tcl_Interp *interp;
     SNMP_Session *session;
-    char *request;
+    const char *request;
 {
     u_int id = 0;
-    char *name = Tcl_GetCommandName(interp, session->token);
+    const char *name = Tcl_GetCommandName(interp, session->token);
 
     if (! name) {
 	return TCL_OK;
     }
 
     if (request) {
-	char *p;
+        const char *p;
 	for (p = request; isdigit(*p); p++) {
 	    id = 10 * id + *p - '0';
 	}
@@ -1233,9 +1234,9 @@ Request(interp, session, pdu_type, argc,
     SNMP_Session *session;
     int pdu_type;
     int argc;
-    char **argv;
+    const char **argv;
 {
-    char *cmd = NULL;
+    const char *cmd = NULL;
     SNMP_PDU _pdu;
     SNMP_PDU *pdu = &_pdu;
     
@@ -1288,7 +1289,7 @@ Request(interp, session, pdu_type, argc,
 	if (Tnm_IsOid (*++argv)) {
 	    pdu->trapOID = ckstrdup(*argv);
 	} else {
-	    char *tmp = Tnm_MibGetOid(*argv, 0);
+	    const char *tmp = Tnm_MibGetOid(*argv, 0);
 	    if (! tmp) {
 		Tcl_AppendResult(interp,  "no object \"", *argv, "\"",
 				 (char *) NULL);
@@ -1383,11 +1384,11 @@ Walk(interp, session, argc, argv)
     Tcl_Interp *interp;
     SNMP_Session *session;
     int argc;
-    char **argv;
+    const char **argv;
 {
     int i, j, k, result;
     int oidc, respc;
-    char **oidv = NULL, **respv = NULL;
+    const char **oidv = NULL, **respv = NULL;
     SNMP_PDU _pdu, *pdu = &_pdu;
     int numRepeaters = 0;
     
@@ -1424,7 +1425,7 @@ Walk(interp, session, argc, argv)
     }
     
     for (i = 0; i < oidc; i++) {
-	char *tmp = Tnm_MibGetOid(oidv[i], 0);
+	const char *tmp = Tnm_MibGetOid(oidv[i], 0);
 	if (!tmp) {
 	    Tcl_AppendResult(interp,  "no object \"", oidv[i], "\"",
 			     (char *) NULL);
@@ -1432,9 +1433,10 @@ Walk(interp, session, argc, argv)
 	    Tcl_DStringFree(&pdu->varbind);
             return TCL_ERROR;
 	}
-	oidv[i] = ckalloc(strlen(tmp) + 2);
-	strcpy(oidv[i], tmp);
-	strcat(oidv[i], ".");
+	char *tmp2 = ckalloc(strlen(tmp) + 2);
+	strcpy(tmp2, tmp);
+	strcat(tmp2, ".");
+	oidv[i] = tmp2;
 	Tcl_DStringAppendElement(&pdu->varbind, tmp);
     }
 
@@ -1468,7 +1470,7 @@ Walk(interp, session, argc, argv)
 
 	result = Tnm_SnmpEncode(interp, session, pdu, NULL, NULL);
 	if (result == TCL_ERROR 
-	    && (strncmp(interp->result, "noSuchName ", 11) == 0)) {
+	    && (strncmp(Tcl_GetStringResult(interp), "noSuchName ", 11) == 0)) {
 	    result = TCL_OK;
 	    goto loopDone;
 	}
@@ -1477,7 +1479,8 @@ Walk(interp, session, argc, argv)
         }
 	
 	if (respv) ckfree((char *) respv);
-	result = Tcl_SplitList(interp, interp->result, &respc, &respv);
+	result = Tcl_SplitList(interp,
+			       Tcl_GetStringResult(interp), &respc, &respv);
 	if (result != TCL_OK) {
 	    goto loopDone;
 	}
@@ -1502,7 +1505,7 @@ Walk(interp, session, argc, argv)
 	    Tcl_DStringFree(&pdu->varbind);
 	    for (k = j * oidc; k < (j+1) * oidc; k++) {
 		int vbc;
-		char **vbv;
+		const char **vbv;
 		result = Tcl_SplitList(interp, respv[k], &vbc, &vbv);
 		if (result != TCL_OK) {
 		    goto loopDone;
@@ -1532,7 +1535,7 @@ Walk(interp, session, argc, argv)
 		} else if (result == TCL_ERROR) {
 		    char msg[100];
 		    sprintf(msg, "\n    (\"%s walk\" body line %d)",
-			    session->name, interp->errorLine);
+			    session->name, Tcl_GetErrorLine(interp));
 		    Tcl_AddErrorInfo(interp, msg);
 		    goto loopDone;
 		} else {
@@ -1556,7 +1559,7 @@ Walk(interp, session, argc, argv)
      */
 
     if (result == TCL_ERROR 
-	&& (strncmp(interp->result, "noSuchName", 10) == 0)) {
+	&& (strncmp(Tcl_GetStringResult(interp), "noSuchName", 10) == 0)) {
 	result = TCL_OK;
     }
 
@@ -1586,11 +1589,11 @@ Walk(interp, session, argc, argv)
 static int
 ExpandTable(interp, tList, dst)
     Tcl_Interp *interp;
-    char *tList;
+    const char *tList;
     Tcl_DString *dst;
 {
     int i, argc, code;
-    char **argv = NULL;
+    const char **argv = NULL;
     Tnm_MibNode *nodePtr, *entryPtr = NULL, *tablePtr = NULL;
     
     code = Tcl_SplitList(interp, tList, &argc, &argv);
@@ -1702,12 +1705,12 @@ Table(interp, session, argc, argv)
     Tcl_Interp *interp;
     SNMP_Session *session;
     int argc;
-    char **argv;
+    const char **argv;
 {
     int i, largc, code;
     SNMP_PDU _pdu, *pdu = &_pdu;
     Tcl_DString varList;
-    char **largv;
+    const char **largv;
     
     if (argc !=  3) {
 	Tcl_AppendResult(interp, "wrong # args: should be \"",
@@ -1791,11 +1794,11 @@ Table(interp, session, argc, argv)
 static int
 ExpandScalars(interp, sList, dst)
     Tcl_Interp *interp;
-    char *sList;
+    const char *sList;
     Tcl_DString *dst;
 {
     int argc, code, i;
-    char **argv = NULL;
+    const char **argv = NULL;
     Tnm_MibNode *nodePtr;
     Tnm_Oid oid[TNM_OIDMAXLEN];
     int oidLen;
@@ -1881,13 +1884,13 @@ Scalars(interp, session, argc, argv)
     Tcl_Interp *interp;
     SNMP_Session *session;
     int argc;
-    char **argv;
+    const char **argv;
 {
     int i, largc, code;
     SNMP_PDU _pdu, *pdu = &_pdu;
     Tcl_DString varList;
     Tcl_DString result;
-    char **largv;
+    const char **largv;
     
     if (argc !=  3) {
 	Tcl_AppendResult(interp, "wrong # args: should be \"",
@@ -1941,7 +1944,7 @@ Scalars(interp, session, argc, argv)
 		      Tcl_DStringLength(&varList));
     code = Tnm_SnmpEncode(interp, session, pdu, NULL, NULL);
     if (code == TCL_OK) {	
-	ScalarSetVar(interp, interp->result, argv[2], &result);
+        ScalarSetVar(interp, Tcl_GetStringResult(interp), argv[2], &result);
 	Tcl_DStringFree(&varList);
 	Tcl_DStringResult(interp, &result);
 	return TCL_OK;
@@ -1952,7 +1955,7 @@ Scalars(interp, session, argc, argv)
      * talking to us. This saves some time-outs.
      */
 
-    if (strcmp(interp->result, "noResponse") == 0) {
+    if (strcmp(Tcl_GetStringResult(interp), "noResponse") == 0) {
 	return TCL_ERROR;
     }
 
@@ -1982,7 +1985,7 @@ Scalars(interp, session, argc, argv)
 	    continue;
 	}
 
-	ScalarSetVar(interp, interp->result, argv[2], &result);
+	ScalarSetVar(interp, Tcl_GetStringResult(interp), argv[2], &result);
     }
     ckfree((char *) largv);
     Tcl_DStringFree(&varList);
@@ -2011,8 +2014,8 @@ Scalars(interp, session, argc, argv)
 static void
 ScalarSetVar(interp, vbl, varName, result)
     Tcl_Interp *interp;
-    char *vbl;
-    char *varName;
+    const char *vbl;
+    const char *varName;
     Tcl_DString *result;
 {
     int i, code, varBindSize;
@@ -2025,7 +2028,7 @@ ScalarSetVar(interp, vbl, varName, resul
     
     for (i = 0; i < varBindSize; i++) {
         Tnm_MibNode *nodePtr = Tnm_MibFindNode(varBindPtr[i].soid, NULL, 0);
-	char *name = nodePtr ? nodePtr->label : varBindPtr[i].soid;
+	const char *name = nodePtr ? nodePtr->label : varBindPtr[i].soid;
 	
 	if ((strcmp(varBindPtr[i].syntax, "noSuchObject") == 0)
 	    || (strcmp(varBindPtr[i].syntax, "noSuchInstance") == 0)
