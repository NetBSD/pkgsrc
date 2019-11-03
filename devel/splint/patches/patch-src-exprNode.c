$NetBSD: patch-src-exprNode.c,v 1.1 2019/11/03 10:55:22 rillig Exp $

Fix the return type of shift expressions.

https://github.com/splintchecker/splint/issues/13
https://github.com/splintchecker/splint/commit/5201227f3eb70887df10b13c6bea3049a228d2ca.patch

---
 src/exprNode.c | 4 +++-
 1 file changed, 3 insertions(+), 1 deletion(-)

diff --git a/src/exprNode.c b/src/exprNode.c
index 8f2b618..d6c581a 100644
--- src/exprNode.c
+++ src/exprNode.c
@@ -5685,6 +5685,7 @@ exprNode_makeOp (/*@keep@*/ exprNode e1, /*@keep@*/ exprNode e2,
     case OR_ASSIGN:
       {
 	bool reported = FALSE;
+        bool shifted = FALSE;
 	
 	/*
 	** Shift Operator 
@@ -5693,6 +5694,7 @@ exprNode_makeOp (/*@keep@*/ exprNode e1, /*@keep@*/ exprNode e2,
 	if (opid == LEFT_OP || opid == LEFT_ASSIGN
 	    || opid == RIGHT_OP || opid == RIGHT_ASSIGN) 
 	  {
+	    shifted = TRUE;
 	    /*
 	    ** evans 2002-01-01: fixed this to follow ISO 6.5.7.
 	    */
@@ -5772,7 +5774,7 @@ exprNode_makeOp (/*@keep@*/ exprNode e1, /*@keep@*/ exprNode e2,
 	** tret is the widest type of te1 and te2 
 	*/
 	
-	tret = ctype_widest (te1, te2);
+	tret = shifted ? te1 : ctype_widest (te1, te2);
 	break;
       }
     case MOD_ASSIGN:
