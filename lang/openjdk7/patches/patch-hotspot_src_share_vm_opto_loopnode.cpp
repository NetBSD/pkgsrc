$NetBSD: patch-hotspot_src_share_vm_opto_loopnode.cpp,v 1.1 2012/11/22 11:02:05 marino Exp $

Patch taken from upstream: 
SUBJ: Don't return booleans from methods returning pointers
http://hg.openjdk.java.net/hsx/hotspot-rt/hotspot/rev/f457154eee8b

Fixes build on gcc 4.7

--- hotspot/src/share/vm/opto/loopnode.cpp.orig	2011-06-27 16:14:21.000000000 +0000
+++ hotspot/src/share/vm/opto/loopnode.cpp
@@ -893,7 +893,7 @@ Node *LoopLimitNode::Identity( PhaseTran
 Node* CountedLoopNode::match_incr_with_optional_truncation(
                       Node* expr, Node** trunc1, Node** trunc2, const TypeInt** trunc_type) {
   // Quick cutouts:
-  if (expr == NULL || expr->req() != 3)  return false;
+  if (expr == NULL || expr->req() != 3)  return NULL;
 
   Node *t1 = NULL;
   Node *t2 = NULL;
