$NetBSD: patch-tnm_snmp_tnmMibTree.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.

--- tnm/snmp/tnmMibTree.c.orig	1996-07-16 19:29:56.000000000 +0000
+++ tnm/snmp/tnmMibTree.c
@@ -36,14 +36,14 @@ static Tcl_HashTable *nodeHashTable = NU
  */
 
 static Tnm_MibNode*
-LookupOID		_ANSI_ARGS_((Tnm_MibNode *root, char *label,
+LookupOID		_ANSI_ARGS_((Tnm_MibNode *root, const char *label,
 				     int *offset, int exact));
 static Tnm_MibNode*
-LookupLabelOID		_ANSI_ARGS_((Tnm_MibNode *root, char *label,
+LookupLabelOID		_ANSI_ARGS_((Tnm_MibNode *root, const char *label,
 				     int *offset, int exact));
 static Tnm_MibNode*
-LookupLabel		_ANSI_ARGS_((Tnm_MibNode *root, char *start, 
-				     char *label, char *moduleName,
+LookupLabel		_ANSI_ARGS_((Tnm_MibNode *root, const char *start, 
+				     const char *label, const char *moduleName,
 				     int *offset, int exact, int fuzzy));
 static void
 HashNode		_ANSI_ARGS_((Tnm_MibNode *node));
@@ -84,14 +84,14 @@ HashNodeLabel		_ANSI_ARGS_((char *label)
 static Tnm_MibNode*
 LookupOID(root, label, offset, exact)
     Tnm_MibNode *root;
-    char *label;
+    const char *label;
     int *offset;
     int exact;
 {
     Tnm_Oid *id;
     int i, len;
     Tnm_MibNode *p, *q = NULL;
-    char *s = label;
+    const char *s = label;
 
     if (offset) *offset = -1;
 
@@ -153,7 +153,7 @@ LookupOID(root, label, offset, exact)
 static Tnm_MibNode*
 LookupLabelOID(root, label, offset, exact)
     Tnm_MibNode *root;
-    char *label;
+    const char *label;
     int *offset;
     int exact;
 {
@@ -212,15 +212,16 @@ LookupLabelOID(root, label, offset, exac
 static Tnm_MibNode*
 LookupLabel(root, start, label, moduleName, offset, exact, fuzzy)
     Tnm_MibNode *root;
-    char *start;
-    char *label;
-    char *moduleName;
+    const char *start;
+    const char *label;
+    const char *moduleName;
     int *offset;
     int exact;
     int fuzzy;
 {
     char head[TNM_OIDMAXLEN * 8];
-    char *tail = label, *p = head;
+    const char *tail = label;
+    char *p = head;
     Tnm_MibNode *tp = NULL, *brother;
     int num = 1;
 
@@ -295,7 +296,7 @@ LookupLabel(root, start, label, moduleNa
 
 Tnm_MibNode*
 Tnm_MibFindNode(name, offset, exact)
-    char *name;
+    const char *name;
     int *offset;
     int exact;
 {
@@ -422,7 +423,7 @@ Tnm_MibAddTC(tcPtr)
 
 Tnm_MibTC*
 Tnm_MibFindTC(name)
-    char *name;
+    const char *name;
 {
     Tcl_HashEntry *entryPtr;
     
@@ -457,7 +458,7 @@ Tnm_MibFindTC(name)
 
 Tnm_MibNode*
 Tnm_MibNewNode(label)
-    char *label;
+    const char *label;
 {
     Tnm_MibNode *nodePtr = (Tnm_MibNode *) ckalloc(sizeof(Tnm_MibNode));
     memset((char *) nodePtr, 0, sizeof(Tnm_MibNode));
