$NetBSD: patch-src_execute-cw.c,v 1.1 2022/12/24 14:24:34 wiz Exp $

Avoid inline to fix build on NetBSD 9.

--- src/execute-cw.c.orig	2000-03-30 20:21:34.000000000 +0000
+++ src/execute-cw.c
@@ -86,7 +86,7 @@ inline int get_value (struct cw_operand 
     }
 }
 
-inline int get_reference (struct cw_operand *o, int i, struct cell **ref)
+int get_reference (struct cw_operand *o, int i, struct cell **ref)
 {
   int j;
 
