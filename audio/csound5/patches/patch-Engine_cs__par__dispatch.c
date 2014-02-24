$NetBSD: patch-Engine_cs__par__dispatch.c,v 1.1 2014/02/24 16:19:39 joerg Exp $

--- Engine/cs_par_dispatch.c.orig	2014-02-24 13:00:33.000000000 +0000
+++ Engine/cs_par_dispatch.c
@@ -1488,21 +1488,6 @@ static inline void csp_dag_prepare_use_i
     }
 }
 
-inline int csp_dag_is_finished(DAG *dag)
-{
-#ifdef CAUTIOUS
-    if (dag == NULL)
-      csound->Die(csound, Str("Invalid NULL Parameter dag"));
-#endif
-    /* TAKE_LOCK(&(dag->spinlock));
-       int res = (dag->remaining <= 0);
-       RELS_LOCK(&(dag->spinlock));
-       return res;
-    */
-    TRACE_5("DAG is finished %d\n", dag->remaining <= 0);
-    return (dag->remaining <= 0);
-}
-
 static void csp_dag_calculate_max_roots(DAG *dag)
 {
     //INSTR_SEMANTICS *instr = NULL;
