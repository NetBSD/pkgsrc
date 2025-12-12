$NetBSD: patch-op.c,v 1.1 2025/12/12 08:11:40 wiz Exp $

Fix a segfault when compiling a 2-var for loop over builtin::indexed.

This is upstream git commit 96673a4bb36, with the following commit
message:
 
 newFOROP: fix crash when optimizing 2-var for over builtin::indexed
 
 OP_ENTERSUB isn't necessarily a LISTOP, apparently, so we can't just
 grab its op_last. Instead, copy/paste logic from elsewhere in op.c to
 find the cvop.
 
 Also, avoid crashing on "fake" pad entries that represent lexical subs
 from outer scopes by climbing up the scope chain until we reach a real
 pad entry.
 
 Fixes #23405.

diff d83bd2549fce92d161cd621b02e1f3c83162a718 96673a4bb36a973a9a4c5cd0e5727a799789a32c
--- op.c.orig	2025-06-24 15:23:21.000000000 +0000
+++ op.c
@@ -9665,7 +9665,7 @@ S_op_is_cv_xsub(pTHX_ OP *o, XSUBADDR_t 
         }
 
         case OP_PADCV:
-            cv = (CV *)PAD_SVl(o->op_targ);
+            cv = find_lexical_cv(o->op_targ);
             assert(cv && SvTYPE(cv) == SVt_PVCV);
             break;
 
@@ -9683,10 +9683,18 @@ S_op_is_cv_xsub(pTHX_ OP *o, XSUBADDR_t 
 static bool
 S_op_is_call_to_cv_xsub(pTHX_ OP *o, XSUBADDR_t xsub)
 {
-    if(o->op_type != OP_ENTERSUB)
+    if (o->op_type != OP_ENTERSUB)
         return false;
 
-    OP *cvop = cLISTOPx(cUNOPo->op_first)->op_last;
+    /* entersub may be a UNOP, not a LISTOP, so we can't just use op_last */
+    OP *aop = cUNOPo->op_first;
+    if (!OpHAS_SIBLING(aop)) {
+        aop = cUNOPx(aop)->op_first;
+    }
+    aop = OpSIBLING(aop);
+    OP *cvop;
+    for (cvop = aop; OpHAS_SIBLING(cvop); cvop = OpSIBLING(cvop)) ;
+
     return op_is_cv_xsub(cvop, xsub);
 }
 
