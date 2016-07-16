$NetBSD: patch-signer_src_signer_ixfr.c,v 1.1 2016/07/16 19:49:07 he Exp $

The part->soamin assertion seems to trigger.
Be helpful and log the zone name before the assert.

--- signer/src/signer/ixfr.c.orig	2016-01-21 14:31:54.000000000 +0000
+++ signer/src/signer/ixfr.c
@@ -227,6 +227,9 @@ part_print(FILE* fd, ixfr_type* ixfr, si
     }
     ods_log_assert(part->min);
     ods_log_assert(part->plus);
+    if (!part->soamin) {
+	ods_log_error("[%s] zone %s no part->soamin", ixfr_str, zone->name);
+    }
     ods_log_assert(part->soamin);
     ods_log_assert(part->soaplus);
     if (util_rr_print(fd, part->soamin) != ODS_STATUS_OK) {
