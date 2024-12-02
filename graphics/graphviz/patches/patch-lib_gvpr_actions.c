$NetBSD: patch-lib_gvpr_actions.c,v 1.1 2024/12/02 16:02:30 jperkin Exp $

Avoid lock_t.

--- lib/gvpr/actions.c.orig	2024-12-02 15:59:23.387253475 +0000
+++ lib/gvpr/actions.c
@@ -502,7 +502,7 @@ int lockGraph(Agraph_t *g, int v) {
     if (data->lock.zombie)
       agclose(g);
     else
-      data->lock = (lock_t){0};
+      data->lock = (gvprlock_t){0};
   }
   return oldv;
 }
