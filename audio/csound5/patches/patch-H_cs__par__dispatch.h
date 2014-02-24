$NetBSD: patch-H_cs__par__dispatch.h,v 1.1 2014/02/24 16:19:39 joerg Exp $

--- H/cs_par_dispatch.h.orig	2014-02-24 13:00:48.000000000 +0000
+++ H/cs_par_dispatch.h
@@ -107,7 +107,20 @@ void csp_dag_build(CSOUND *csound, DAG *
 void csp_dag_print(CSOUND *csound, DAG *dag);
 
 /* return 1 if the DAG is completely consume */
-inline int csp_dag_is_finished(DAG *dag);
+static inline int csp_dag_is_finished(DAG *dag)
+{
+#ifdef CAUTIOUS
+    if (dag == NULL)
+      csound->Die(csound, Str("Invalid NULL Parameter dag"));
+#endif
+    /* TAKE_LOCK(&(dag->spinlock));
+       int res = (dag->remaining <= 0);
+       RELS_LOCK(&(dag->spinlock));
+       return res;
+    */
+    TRACE_5("DAG is finished %d\n", dag->remaining <= 0);
+    return (dag->remaining <= 0);
+}
 /* get a node from the dag
  * update_hdl should be passed into consume_update when the node has
  * been performed */
