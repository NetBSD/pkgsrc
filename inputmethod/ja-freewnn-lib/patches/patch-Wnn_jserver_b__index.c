$NetBSD: patch-Wnn_jserver_b__index.c,v 1.1 2026/07/10 23:32:37 tsutsui Exp $

- Appease -Wpointer-compare

--- Wnn/jserver/b_index.c.orig	2003-06-07 02:23:58.000000000 +0000
+++ Wnn/jserver/b_index.c
@@ -314,7 +314,7 @@ bnode_alloc (struct JT *jt)
       return (i);
     }
   if (b_cnt++ >= jt->bufsize_bnode)     /* Use new  b_nodes */
-    if (rd_realloc_bind (jt) == NULL)	/* realloc jt->bind */
+    if (rd_realloc_bind (jt) == 0)	/* realloc jt->bind */
       return (-1);
   return (jt->bufsize_bnode = b_cnt);   /* Not re-alloc */
 }
