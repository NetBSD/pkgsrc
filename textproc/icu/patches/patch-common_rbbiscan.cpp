$NetBSD: patch-common_rbbiscan.cpp,v 1.1.2.1 2017/04/25 17:54:53 bsiegert Exp $

Backport upstream changeset 39669
ticket:12932 RBBI rule parsing, fix incorrect handling of node stack overflow.

--- common/rbbiscan.cpp.orig	2016-07-22 21:50:34.000000000 +0000
+++ common/rbbiscan.cpp
@@ -1179,13 +1179,12 @@ RBBINode  *RBBIRuleScanner::pushNewNode(
     if (U_FAILURE(*fRB->fStatus)) {
         return NULL;
     }
-    fNodeStackPtr++;
-    if (fNodeStackPtr >= kStackSize) {
-        error(U_BRK_INTERNAL_ERROR);
+    if (fNodeStackPtr >= kStackSize - 1) {
+        error(U_BRK_RULE_SYNTAX);
         RBBIDebugPuts("RBBIRuleScanner::pushNewNode - stack overflow.");
-        *fRB->fStatus = U_BRK_INTERNAL_ERROR;
         return NULL;
     }
+    fNodeStackPtr++;
     fNodeStack[fNodeStackPtr] = new RBBINode(t);
     if (fNodeStack[fNodeStackPtr] == NULL) {
         *fRB->fStatus = U_MEMORY_ALLOCATION_ERROR;
