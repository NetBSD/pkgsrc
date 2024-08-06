$NetBSD: patch-xlators_debug_io-stats_src_io-stats.c,v 1.1 2024/08/06 18:54:02 riastradh Exp $

Avoid ctype(3) abuse.

--- xlators/debug/io-stats/src/io-stats.c.orig	2020-09-16 18:40:32.399503676 +0000
+++ xlators/debug/io-stats/src/io-stats.c
@@ -862,7 +862,7 @@ io_stats_dump_global_to_json_logfp(xlato
     for (i = 0; i < GF_FOP_MAXVALUE; i++) {
         lc_fop_name = strdupa(gf_fop_list[i]);
         for (j = 0; lc_fop_name[j]; j++) {
-            lc_fop_name[j] = tolower(lc_fop_name[j]);
+            lc_fop_name[j] = tolower((unsigned char)lc_fop_name[j]);
         }
 
         fop_hits = GF_ATOMIC_GET(stats->fop_hits[i]);
@@ -919,7 +919,7 @@ io_stats_dump_global_to_json_logfp(xlato
     for (i = 0; i < GF_UPCALL_FLAGS_MAXVALUE; i++) {
         lc_fop_name = strdupa(gf_upcall_list[i]);
         for (j = 0; lc_fop_name[j]; j++) {
-            lc_fop_name[j] = tolower(lc_fop_name[j]);
+            lc_fop_name[j] = tolower((unsigned char)lc_fop_name[j]);
         }
         fop_hits = GF_ATOMIC_GET(stats->upcall_hits[i]);
         if (interval == -1) {
