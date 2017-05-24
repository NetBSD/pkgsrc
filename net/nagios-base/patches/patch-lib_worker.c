$NetBSD: patch-lib_worker.c,v 1.3 2017/05/24 07:42:39 manu Exp $

64bit time_t workaround

--- lib/worker.c.orig	2017-05-22 09:36:34.000000000 +0200
+++ lib/worker.c	2017-05-22 09:35:40.000000000 +0200
@@ -303,16 +303,16 @@
 		}
 		kvvec_addkv_wlen(&resp, kv->key, kv->key_len, kv->value, kv->value_len);
 	}
 	kvvec_addkv(&resp, "wait_status", mkstr("%d", cp->ret));
-	kvvec_add_tv(&resp, "start", cp->ei->start);
-	kvvec_add_tv(&resp, "stop", cp->ei->stop);
+	kvvec_add_tv(&resp, "start", (unsigned long)cp->ei->start);
+	kvvec_add_tv(&resp, "stop", (unsigned long)cp->ei->stop);
 	kvvec_addkv(&resp, "runtime", mkstr("%f", cp->ei->runtime));
 	if (!reason) {
 		/* child exited nicely (or with a signal, so check wait_status) */
 		kvvec_addkv(&resp, "exited_ok", "1");
-		kvvec_add_tv(&resp, "ru_utime", ru->ru_utime);
-		kvvec_add_tv(&resp, "ru_stime", ru->ru_stime);
+		kvvec_add_tv(&resp, "ru_utime", (unsigned long)ru->ru_utime);
+		kvvec_add_tv(&resp, "ru_stime", (unsigned long)ru->ru_stime);
 		kvvec_add_long(&resp, "ru_minflt", ru->ru_minflt);
 		kvvec_add_long(&resp, "ru_majflt", ru->ru_majflt);
 		kvvec_add_long(&resp, "ru_inblock", ru->ru_inblock);
 		kvvec_add_long(&resp, "ru_oublock", ru->ru_oublock);
