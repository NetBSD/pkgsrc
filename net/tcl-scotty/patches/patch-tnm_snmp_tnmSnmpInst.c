$NetBSD: patch-tnm_snmp_tnmSnmpInst.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.

--- tnm/snmp/tnmSnmpInst.c.orig	1997-09-09 21:17:12.000000000 +0200
+++ tnm/snmp/tnmSnmpInst.c	2014-03-04 22:56:58.000000000 +0100
@@ -30,20 +30,23 @@
 FreeNode		_ANSI_ARGS_((TnmSnmpNode *inst));
 
 static TnmSnmpNode*
-AddNode			_ANSI_ARGS_((char *id, int offset, int syntax,
-				     int access, char *tclVarName));
+AddNode			_ANSI_ARGS_((const char *id, int offset, int syntax,
+				     int access, const char *tclVarName));
 static void
-RemoveNode		_ANSI_ARGS_((TnmSnmpNode *root, char *varname));
+RemoveNode		_ANSI_ARGS_((TnmSnmpNode *root, const char *varname));
 
 static TnmSnmpNode*
-FindNode		_ANSI_ARGS_((TnmSnmpNode *root, Tnm_Oid *oid, int len));
+FindNode		_ANSI_ARGS_((TnmSnmpNode *root, const Tnm_Oid *oid,
+				     int len));
 
 static TnmSnmpNode*
-FindNextNode		_ANSI_ARGS_((TnmSnmpNode *root, Tnm_Oid *oid, int len));
+FindNextNode		_ANSI_ARGS_((TnmSnmpNode *root, const Tnm_Oid *oid,
+				     int len));
 
 static char*
 DeleteNodeProc		_ANSI_ARGS_((ClientData clientData, Tcl_Interp *interp,
-				     char *name1, char *name2, int flags));
+				     const char *name1, const char *name2,
+				     int flags));
 
 
 /*
@@ -138,11 +141,11 @@
 
 static TnmSnmpNode*
 AddNode(soid, offset, syntax, access, tclVarName)
-    char *soid;
+    const char *soid;
     int offset;
     int syntax;
     int access;
-    char *tclVarName;
+    const char *tclVarName;
 {
     Tnm_Oid *oid;
     int i, oidlen;
@@ -239,7 +242,7 @@
 static TnmSnmpNode*
 FindNextNode(root, oid, len)
     TnmSnmpNode *root;
-    Tnm_Oid *oid;
+    const Tnm_Oid *oid;
     int len;
 {
     TnmSnmpNode *p, *inst;
@@ -321,7 +324,7 @@
 static TnmSnmpNode*
 FindNode(root, oid, len)
     TnmSnmpNode *root;
-    Tnm_Oid *oid;
+    const Tnm_Oid *oid;
     int len;
 {
     TnmSnmpNode *p, *q = NULL;
@@ -359,7 +362,7 @@
 static void
 RemoveNode(root, varName)
     TnmSnmpNode *root;
-    char *varName;
+    const char *varName;
 {
     TnmSnmpNode *p, *q;
 
@@ -407,8 +410,8 @@
 DeleteNodeProc(clientData, interp, name1, name2, flags)
     ClientData clientData;
     Tcl_Interp *interp;
-    char *name1;
-    char *name2;
+    const char *name1;
+    const char *name2;
     int flags;
 {
     int len = strlen(name1);
@@ -451,14 +454,14 @@
 int
 Tnm_SnmpCreateNode(interp, label, tclVarName, defval)
     Tcl_Interp *interp;
-    char *label;
-    char *tclVarName;
-    char *defval;
+    const char *label;
+    const char *tclVarName;
+    const char *defval;
 {
     char *soid = NULL;
     Tnm_MibNode *nodePtr = Tnm_MibFindNode(label, NULL, 0);
     int access, offset = 0, syntax = 0;
-    char *varName = NULL;
+    const char *varName = NULL;
 
     if (!nodePtr || nodePtr->childPtr) {
 	Tcl_AppendResult(interp, "unknown object type \"", label, "\"", 
@@ -586,7 +589,7 @@
 TnmSnmpNode*
 Tnm_SnmpFindNode(session, oid, oidlen)
     SNMP_Session *session;
-    Tnm_Oid *oid;
+    const Tnm_Oid *oid;
     int oidlen;
 {
     return FindNode(instTree, oid, oidlen);
@@ -612,7 +615,7 @@
 TnmSnmpNode*
 Tnm_SnmpFindNextNode(session, oid, oidlen)
     SNMP_Session *session;
-    Tnm_Oid *oid;
+    const Tnm_Oid *oid;
     int oidlen;
 {
     return FindNextNode(instTree, oid, oidlen);
@@ -638,10 +641,10 @@
 int
 Tnm_SnmpSetNodeBinding(session, oid, oidlen, event, command)
     SNMP_Session *session;
-    Tnm_Oid *oid;
+    const Tnm_Oid *oid;
     int oidlen;
     int event;
-    char *command;
+    const char *command;
 {
     TnmSnmpNode *node = NULL;
     SNMP_Binding *bindPtr = NULL;
@@ -713,7 +716,7 @@
 char*
 Tnm_SnmpGetNodeBinding(session, oid, oidlen, event)
     SNMP_Session *session;
-    Tnm_Oid *oid;
+    const Tnm_Oid *oid;
     int oidlen;
     int event;
 {
@@ -761,13 +764,13 @@
     SNMP_PDU *pdu;
     TnmSnmpNode *inst;
     int event;
-    char *value;
+    const char *value;
     char *oldValue;
 {
     int oidlen;
-    Tnm_Oid *oid;
+    const Tnm_Oid *oid;
     int code = TCL_OK;
-    char *instOid;
+    const char *instOid;
     
     oid = Tnm_StrToOid(inst->label, &oidlen);
     instOid = inst->label+inst->offset;
