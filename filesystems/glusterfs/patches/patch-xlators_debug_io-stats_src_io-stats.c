$NetBSD: patch-xlators_debug_io-stats_src_io-stats.c,v 1.2 2024/08/06 21:10:47 riastradh Exp $

Avoid ctype(3) abuse.
https://github.com/gluster/glusterfs/issues/4397

--- xlators/debug/io-stats/src/io-stats.c.orig	2023-04-06 09:01:24.932968070 +0000
+++ xlators/debug/io-stats/src/io-stats.c
@@ -848,7 +848,7 @@ io_stats_dump_global_to_json_logfp(xlato
     for (i = 0; i < GF_FOP_MAXVALUE; i++) {
         lc_fop_name = strdupa(gf_fop_list[i]);
         for (j = 0; lc_fop_name[j]; j++) {
-            lc_fop_name[j] = tolower(lc_fop_name[j]);
+            lc_fop_name[j] = tolower((unsigned char)lc_fop_name[j]);
         }
 
         fop_hits = GF_ATOMIC_GET(stats->fop_hits[i]);
@@ -905,7 +905,7 @@ io_stats_dump_global_to_json_logfp(xlato
     for (i = 0; i < GF_UPCALL_FLAGS_MAXVALUE; i++) {
         lc_fop_name = strdupa(gf_upcall_list[i]);
         for (j = 0; lc_fop_name[j]; j++) {
-            lc_fop_name[j] = tolower(lc_fop_name[j]);
+            lc_fop_name[j] = tolower((unsigned char)lc_fop_name[j]);
         }
         fop_hits = GF_ATOMIC_GET(stats->upcall_hits[i]);
         if (interval == -1) {
