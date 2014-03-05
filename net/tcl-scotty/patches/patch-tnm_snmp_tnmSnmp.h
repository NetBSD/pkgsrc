$NetBSD: patch-tnm_snmp_tnmSnmp.h,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.

--- tnm/snmp/tnmSnmp.h.orig	1998-04-23 11:16:19.000000000 +0000
+++ tnm/snmp/tnmSnmp.h
@@ -213,9 +213,9 @@ EXTERN SNMP_Session *sessionList;
  */
 
 typedef struct SNMP_VarBind {
-    char *soid;
-    char *syntax;
-    char *value;
+    const char *soid;
+    const char *syntax;
+    const char *value;
     char *freePtr;
     ClientData clientData;
     int flags;
@@ -223,9 +223,9 @@ typedef struct SNMP_VarBind {
 
 EXTERN void
 Tnm_SnmpFreeVBList	_ANSI_ARGS_((int varBindSize, 
-				     SNMP_VarBind *varBindPtr));
+				     const SNMP_VarBind *varBindPtr));
 EXTERN int
-Tnm_SnmpSplitVBList	_ANSI_ARGS_((Tcl_Interp *interp, char *list,
+Tnm_SnmpSplitVBList	_ANSI_ARGS_((Tcl_Interp *interp, const char *list,
 				     int *varBindSizePtr, 
 				     SNMP_VarBind **varBindPtrPtr));
 EXTERN char*
@@ -355,11 +355,11 @@ Tnm_SnmpEvalBinding	_ANSI_ARGS_((Tcl_Int
  */
 
 typedef struct TnmSnmpNode {
-    char *label;			/* The complete OID.	    */
+    const char *label;			/* The complete OID.	    */
     int offset;				/* Offset to instance id.   */
     int syntax;				/* Syntax string from MIB.  */
     int	access;				/* Access mode from MIB.    */
-    char *tclVarName;			/* Tcl variable name.	    */
+    const char *tclVarName;		/* Tcl variable name.	    */
     SNMP_Binding *bindings;		/* List of bindings.        */ 
     u_int subid;			/* Sub identifier in Tree.  */
     struct TnmSnmpNode *childPtr;	        /* List of child nodes.	    */
@@ -367,25 +367,25 @@ typedef struct TnmSnmpNode {
 } TnmSnmpNode;
 
 EXTERN int
-Tnm_SnmpCreateNode	_ANSI_ARGS_((Tcl_Interp *interp, char *id,
-				     char *varName, char *defval));
+Tnm_SnmpCreateNode	_ANSI_ARGS_((Tcl_Interp *interp, const char *id,
+				     const char *varName, const char *defval));
 EXTERN TnmSnmpNode*
 Tnm_SnmpFindNode	_ANSI_ARGS_((SNMP_Session *session,
-				     Tnm_Oid *oid, int len));
+				     const Tnm_Oid *oid, int len));
 EXTERN TnmSnmpNode*
 Tnm_SnmpFindNextNode	_ANSI_ARGS_((SNMP_Session *session,
-				     Tnm_Oid *oid, int len));
+				     const Tnm_Oid *oid, int len));
 EXTERN int
 Tnm_SnmpSetNodeBinding	_ANSI_ARGS_((SNMP_Session *session,
-				     Tnm_Oid *oid, int len,
-				     int event, char *command));
+				     const Tnm_Oid *oid, int len,
+				     int event, const char *command));
 EXTERN char*
 Tnm_SnmpGetNodeBinding	_ANSI_ARGS_((SNMP_Session *session,
-				     Tnm_Oid *oid, int len, int event));
+				     const Tnm_Oid *oid, int len, int event));
 EXTERN int
 Tnm_SnmpEvalNodeBinding	_ANSI_ARGS_((SNMP_Session *session,
 				     SNMP_PDU *pdu, TnmSnmpNode *inst,
-				     int operation, char *value,
+				     int operation, const char *value,
 				     char *oldValue));
 
 /*
@@ -496,8 +496,9 @@ Tnm_SnmpAgentRequest	_ANSI_ARGS_((Tcl_In
 EXTERN int
 Tnm_SnmpEvalCallback	_ANSI_ARGS_((Tcl_Interp *interp, SNMP_Session *session,
 				     SNMP_PDU *pdu,
-				     char *cmd, char *instance, char *oid, 
-				     char *value, char* oldValue));
+				     const char *cmd, const char *instance,
+				     const char *oid,
+				     const char *value, char* oldValue));
 
 /*
  *----------------------------------------------------------------
@@ -590,10 +591,10 @@ Tnm_SnmpUsecAuth	_ANSI_ARGS_((SNMP_Sessi
 #endif
 
 EXTERN void
-Tnm_SnmpBinToHex	_ANSI_ARGS_((char *s, int n, char *d));
+Tnm_SnmpBinToHex	_ANSI_ARGS_((const char *s, int n, char *d));
 
 EXTERN int
-Tnm_SnmpHexToBin	_ANSI_ARGS_((char *s, char *d, int *n));
+Tnm_SnmpHexToBin	_ANSI_ARGS_((const char *s, char *d, int *n));
 
 EXTERN void
 Tnm_SnmpDumpPDU		_ANSI_ARGS_((Tcl_Interp *interp, SNMP_PDU *pdu));
