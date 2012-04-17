$NetBSD: patch-src_util.c,v 1.1 2012/04/17 17:45:36 joerg Exp $

--- src/util.c.orig	2012-04-16 22:20:17.000000000 +0000
+++ src/util.c
@@ -29,18 +29,6 @@ test_malloc(int x)
   return ret;
 }
 
-inline int
-before(u_int seq1, u_int seq2)
-{
-  return ((int)(seq1 - seq2) < 0);
-}
-
-inline int
-after(u_int seq1, u_int seq2)
-{
-  return ((int)(seq2 - seq1) < 0);
-}
-
 void
 register_callback(struct proc_node **procs, void (*x))
 {
