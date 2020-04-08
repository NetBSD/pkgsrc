$NetBSD: patch-gcc_gimplify.c,v 1.1 2020/04/08 16:35:59 wiz Exp $

Fix -fstack-check on NetBSD.
https://gcc.gnu.org/bugzilla/show_bug.cgi?id=94479

--- gcc/gimplify.c.orig	2020-03-12 11:07:21.000000000 +0000
+++ gcc/gimplify.c
@@ -6086,7 +6086,9 @@ gimplify_addr_expr (tree *expr_p, gimple
 
       /* For various reasons, the gimplification of the expression
 	 may have made a new INDIRECT_REF.  */
-      if (TREE_CODE (op0) == INDIRECT_REF)
+      if (TREE_CODE (op0) == INDIRECT_REF
+         || (TREE_CODE (op0) == MEM_REF
+             && integer_zerop (TREE_OPERAND (op0, 1))))
 	goto do_indirect_ref;
 
       mark_addressable (TREE_OPERAND (expr, 0));
