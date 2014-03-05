$NetBSD: patch-tnm_snmp_tnmMib.h,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.

--- tnm/snmp/tnmMib.h.orig	1996-10-02 06:33:57.000000000 +0000
+++ tnm/snmp/tnmMib.h
@@ -123,59 +123,61 @@ EXTERN Tnm_MibTC *tnm_MibTCSaveMark;	/* 
  *----------------------------------------------------------------
  */
 
-EXTERN char*
-Tnm_MibGetOid		_ANSI_ARGS_((char *name, int exact));
+EXTERN const char*
+Tnm_MibGetOid		_ANSI_ARGS_((const char *name, int exact));
 
 EXTERN char*
-Tnm_MibGetName		_ANSI_ARGS_((char *oid,  int exact));
+Tnm_MibGetName		_ANSI_ARGS_((const char *oid,  int exact));
 
 EXTERN char*
-Tnm_MibGetSyntax	_ANSI_ARGS_((char *name, int exact));
+Tnm_MibGetSyntax	_ANSI_ARGS_((const char *name, int exact));
 
 EXTERN int
-Tnm_MibGetBaseSyntax	_ANSI_ARGS_((char *name, int exact));
+Tnm_MibGetBaseSyntax	_ANSI_ARGS_((const char *name, int exact));
 
 EXTERN char*
-Tnm_MibGetDescription	_ANSI_ARGS_((char *name, int exact));
+Tnm_MibGetDescription	_ANSI_ARGS_((const char *name, int exact));
 
 EXTERN char*
-Tnm_MibGetAccess	_ANSI_ARGS_((char *name, int exact));
+Tnm_MibGetAccess	_ANSI_ARGS_((const char *name, int exact));
 
 EXTERN char*
-Tnm_MibGetMacro		_ANSI_ARGS_((char *name, int exact));
+Tnm_MibGetMacro		_ANSI_ARGS_((const char *name, int exact));
 
 EXTERN char*
-Tnm_MibGetModule	_ANSI_ARGS_((char *name, int exact));
+Tnm_MibGetModule	_ANSI_ARGS_((const char *name, int exact));
 
 EXTERN char*
-Tnm_MibGetSucc		_ANSI_ARGS_((char *name));
+Tnm_MibGetSucc		_ANSI_ARGS_((const char *name));
 
 EXTERN char*
-Tnm_MibGetParent	_ANSI_ARGS_((char *name, int exact));
+Tnm_MibGetParent	_ANSI_ARGS_((const char *name, int exact));
 
 EXTERN char*
-Tnm_MibGetTC		_ANSI_ARGS_((char *name, int exact));
+Tnm_MibGetTC		_ANSI_ARGS_((const char *name, int exact));
 
 EXTERN char*
-Tnm_MibGetFile		_ANSI_ARGS_((char *name, int exact));
+Tnm_MibGetFile		_ANSI_ARGS_((const char *name, int exact));
 
 EXTERN char*
-Tnm_MibGetIndex		_ANSI_ARGS_((char *name, int exact));
+Tnm_MibGetIndex		_ANSI_ARGS_((const char *name, int exact));
 
 EXTERN char*
-Tnm_MibGetDefault	_ANSI_ARGS_((char *name, int exact));
+Tnm_MibGetDefault	_ANSI_ARGS_((const char *name, int exact));
 
 EXTERN int
-Tnm_MibNodeGetOid	_ANSI_ARGS_((Tnm_MibNode *nodePtr, Tnm_Oid *oid));
+Tnm_MibNodeGetOid	_ANSI_ARGS_((const Tnm_MibNode *nodePtr, Tnm_Oid *oid));
 
 EXTERN Tnm_MibNode*
-Tnm_MibFindNode		_ANSI_ARGS_((char *name, int *offset, int exact));
-
-EXTERN char*
-Tnm_MibFormat		_ANSI_ARGS_((char *name, int exact, char *arg));
+Tnm_MibFindNode		_ANSI_ARGS_((const char *name, int *offset, int exact));
 
-EXTERN char*
-Tnm_MibScan		_ANSI_ARGS_((char *name, int exact, char *arg));
+EXTERN const char*
+Tnm_MibFormat		_ANSI_ARGS_((const char *name, int exact,
+				     const char *arg));
+
+EXTERN const char*
+Tnm_MibScan		_ANSI_ARGS_((const char *name, int exact,	
+			     const char *arg));
 
 /*
  *----------------------------------------------------------------
@@ -184,7 +186,7 @@ Tnm_MibScan		_ANSI_ARGS_((char *name, in
  */
 
 EXTERN Tnm_MibNode*
-Tnm_MibParse		_ANSI_ARGS_((char *file, char *frozen,
+Tnm_MibParse		_ANSI_ARGS_((const char *file, const char *frozen,
 				     Tnm_MibNode *root));
 EXTERN Tnm_MibNode*
 Tnm_MibReadFrozen	_ANSI_ARGS_((FILE *fp));
@@ -200,7 +202,7 @@ Tnm_MibWriteFrozen	_ANSI_ARGS_((FILE *fp
  */
 
 EXTERN Tnm_MibNode*
-Tnm_MibNewNode		_ANSI_ARGS_((char *label));
+Tnm_MibNewNode		_ANSI_ARGS_((const char *label));
 
 EXTERN void
 Tnm_MibAddNode		_ANSI_ARGS_((Tnm_MibNode **rootPtr, 
@@ -209,7 +211,7 @@ EXTERN Tnm_MibTC*
 Tnm_MibAddTC		_ANSI_ARGS_((Tnm_MibTC *tcPtr));
 
 EXTERN Tnm_MibTC*
-Tnm_MibFindTC		_ANSI_ARGS_((char *name));
+Tnm_MibFindTC		_ANSI_ARGS_((const char *name));
 
 /*
  *----------------------------------------------------------------
