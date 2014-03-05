$NetBSD: patch-tnm_snmp_tnmMibParser.c,v 1.1 2014/03/05 13:52:29 he Exp $

Constify.

--- tnm/snmp/tnmMibParser.c.orig	1998-10-20 15:51:08.000000000 +0000
+++ tnm/snmp/tnmMibParser.c
@@ -336,8 +336,8 @@ AddNewNode (nodeList, label, parentName,
 
 Tnm_MibNode*
 Tnm_MibParse(file, frozen, root)
-    char *file;
-    char *frozen;
+    const char *file;
+    const char *frozen;
     Tnm_MibNode *root;
 {
     FILE *fp;		/* The current FILE pointer. */
