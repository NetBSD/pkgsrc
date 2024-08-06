$NetBSD: patch-xlators_cluster_ec_src_ec.c,v 1.1 2024/08/06 18:51:19 riastradh Exp $

Fix printf format for uintptr_t.

--- xlators/cluster/ec/src/ec.c.orig	2023-04-06 09:01:24.928968057 +0000
+++ xlators/cluster/ec/src/ec.c
@@ -74,7 +74,7 @@ ec_parse_options(xlator_t *this)
 
     gf_msg_debug("ec", 0,
                  "Initialized with: nodes=%u, fragments=%u, "
-                 "stripe_size=%u, node_mask=%" PRIxFAST32,
+                 "stripe_size=%u, node_mask=%" PRIxPTR,
                  ec->nodes, ec->fragments, ec->stripe_size, ec->node_mask);
 
     error = 0;
