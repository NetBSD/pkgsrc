$NetBSD: patch-signer_src_signer_zone.c,v 1.1 2016/07/16 19:49:07 he Exp $

For debugging, save any corrupted ixfr journal files as <zone>.ixfr-bad.

--- signer/src/signer/zone.c.orig	2016-05-02 10:40:02.000000000 +0000
+++ signer/src/signer/zone.c
@@ -1028,12 +1028,22 @@ zone_recover2(zone_type* zone)
             fd = ods_fopen(filename, NULL, "r");
         }
         if (fd) {
+	    char *badfn = NULL;
+
             status = backup_read_ixfr(fd, zone);
             if (status != ODS_STATUS_OK) {
                 ods_log_warning("[%s] corrupted journal file zone %s, "
                     "skipping (%s)", zone_str, zone->name,
                     ods_status2str(status));
-                (void)unlink(filename);
+		badfn = ods_build_path(zone->name, ".ixfr-bad", 0, 1);
+		if (badfn) {
+		    (void)rename(filename, badfn);
+		    ods_log_warning("[%s] corrupted journal for zone %s "
+			"saved as %s", zone_str, zone->name, badfn);
+		    free(badfn);
+		} else {
+                    (void)unlink(filename);
+		}
                 ixfr_cleanup(zone->ixfr);
                 zone->ixfr = ixfr_create((void*)zone);
             }
