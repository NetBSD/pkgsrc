$NetBSD: patch-lib_yang-data.h,v 1.1 2024/08/05 08:19:59 tnn Exp $

Add missing prototypes.

--- lib/yang-data.h.orig	2013-06-04 12:34:00.000000000 +0000
+++ lib/yang-data.h
@@ -164,6 +164,7 @@ int removeYangNode(_YangNode* target, _Y
 
 _YangModuleInfo *createModuleInfo(_YangNode *modulePtr);
 
+void createIdentifierRef(_YangNode *node, char* prefix, char* ident);
 void createTypeInfo(_YangNode *node);
 
 _YangNode *findYangModuleByName(const char *modulename, char* revision);
