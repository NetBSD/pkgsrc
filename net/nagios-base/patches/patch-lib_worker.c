$NetBSD: patch-lib_worker.c,v 1.4 2023/01/08 23:33:59 sekiya Exp $

64-bit time_t workaround

--- lib/worker.c.orig	2022-11-17 05:52:51.000000000 +0900
+++ lib/worker.c	2023-01-09 07:17:21.535874106 +0900
@@ -304,8 +304,8 @@
 		kvvec_addkv_wlen(&resp, kv->key, kv->key_len, kv->value, kv->value_len);
 	}
 	kvvec_addkv(&resp, "wait_status", mkstr("%d", cp->ret));
-	kvvec_add_tv(&resp, "start", cp->ei->start);
-	kvvec_add_tv(&resp, "stop", cp->ei->stop);
+	kvvec_add_tv(&resp, "start", (unsigned long)cp->ei->start);
+	kvvec_add_tv(&resp, "stop", (unsigned long)cp->ei->stop);
 	kvvec_addkv(&resp, "runtime", mkstr("%f", cp->ei->runtime));
 	if (!reason) {
 		/* child exited nicely */
