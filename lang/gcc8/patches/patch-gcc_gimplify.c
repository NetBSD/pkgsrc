$NetBSD: patch-gcc_gimplify.c,v 1.1 2020/04/08 06:39:57 wiz Exp $

Fix -fstack-check on NetBSD.
https://gcc.gnu.org/bugzilla/show_bug.cgi?id=94479

--- gcc/gimplify.c.orig	2019-02-07 14:44:31.000000000 +0000
+++ gcc/gimplify.c
@@ -6065,7 +6065,9 @@ gimplify_addr_expr (tree *expr_p, gimple
 
       /* For various reasons, the gimplification of the expression
 	 may have made a new INDIRECT_REF.  */
-      if (TREE_CODE (op0) == INDIRECT_REF)
+      if (TREE_CODE (op0) == INDIRECT_REF
+         || (TREE_CODE (op0) == MEM_REF
+             && integer_zerop (TREE_OPERAND (op0, 1))))
 	goto do_indirect_ref;
 
       mark_addressable (TREE_OPERAND (expr, 0));
