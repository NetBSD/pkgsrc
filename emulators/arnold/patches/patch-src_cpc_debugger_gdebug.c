$NetBSD: patch-src_cpc_debugger_gdebug.c,v 1.1 2018/04/09 15:03:22 ryoon Exp $

Fix segfault on quit
https://github.com/rofl0r/arnold/commit/08915c467477ad2316cd5a8997a3538738be8945

--- src/cpc/debugger/gdebug.c.orig	2004-01-03 01:02:20.000000000 +0000
+++ src/cpc/debugger/gdebug.c
@@ -2757,7 +2757,7 @@ void    Debug_DeleteComparisonList(DEBUG
                 pNode = pList->Dummy.pNext;
 
                 /* traverse as long as node isn't the dummy node */
-                while (pNode!=&pList->Dummy)
+                while (pNode && pNode!=&pList->Dummy)
                 {
                         DEBUG_CMP_LIST_NODE *pNext;
 
