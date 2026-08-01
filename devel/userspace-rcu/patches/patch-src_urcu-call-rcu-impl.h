$NetBSD: patch-src_urcu-call-rcu-impl.h,v 1.1.2.2 2026/08/01 19:39:23 maya Exp $

Close memory leak, found in
https://gitlab.isc.org/isc-projects/bind9/-/work_items/5528#note_725072

--- src/urcu-call-rcu-impl.h.orig	2026-07-14 17:15:38.774411659 +0000
+++ src/urcu-call-rcu-impl.h
@@ -333,7 +333,7 @@ static void *call_rcu_thread(void *arg)
 		cmm_smp_mb();
 	}
 	for (;;) {
-		struct cds_wfcq_head cbs_tmp_head;
+		struct __cds_wfcq_head cbs_tmp_head;
 		struct cds_wfcq_tail cbs_tmp_tail;
 		struct cds_wfcq_node *cbs, *cbs_tmp_n;
 		enum cds_wfcq_ret splice_ret;
@@ -358,7 +358,7 @@ static void *call_rcu_thread(void *arg)
 			rcu_register_thread();
 		}
 
-		cds_wfcq_init(&cbs_tmp_head, &cbs_tmp_tail);
+		__cds_wfcq_init(&cbs_tmp_head, &cbs_tmp_tail);
 		splice_ret = __cds_wfcq_splice_blocking(&cbs_tmp_head,
 			&cbs_tmp_tail, &crdp->cbs_head, &crdp->cbs_tail);
 		urcu_posix_assert(splice_ret != CDS_WFCQ_RET_WOULDBLOCK);
@@ -796,6 +796,7 @@ void _call_rcu_data_free(struct call_rcu
 		if (ret)
 			urcu_die(ret);
 	}
+	cds_wfcq_destroy(&crdp->cbs_head, &crdp->cbs_tail);
 	free(crdp);
 }
 
