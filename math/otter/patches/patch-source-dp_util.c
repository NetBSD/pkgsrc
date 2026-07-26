$NetBSD: patch-source-dp_util.c,v 1.1 2026/07/26 06:14:13 rillig Exp $

Add missing types for C23.

--- source/dp_util.c.orig	1999-12-01 21:50:00.000000000 +0000
+++ source/dp_util.c
@@ -792,7 +792,7 @@ static void instances_recurse(struct clause *c,
  *
  *************/
 
-int sym_lessthan(n1, n2)
+int sym_lessthan(int n1, int n2)
 {
   int a1 = sn_to_arity(n1);
   int a2 = sn_to_arity(n2);
