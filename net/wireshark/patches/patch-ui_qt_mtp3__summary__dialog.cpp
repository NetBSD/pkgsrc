$NetBSD: patch-ui_qt_mtp3__summary__dialog.cpp,v 1.1 2016/03/03 13:33:14 wiz Exp $

--- ui/qt/mtp3_summary_dialog.cpp.orig	2015-12-29 21:49:23.000000000 +0000
+++ ui/qt/mtp3_summary_dialog.cpp
@@ -208,7 +208,7 @@ QString Mtp3SummaryDialog::summaryToHtml
         << table_hheader15_tmpl.arg(tr("Bytes/s"))
         << table_row_end;
 
-    for (size_t si_code = 0; si_code < MTP3_NUM_SI_CODE; si_code++) {
+    for (size_t ws_si_code = 0; ws_si_code < MTP3_NUM_SI_CODE; ws_si_code++) {
         int si_msus = 0;
         int si_bytes = 0;
         QString msus_s_str = n_a;
@@ -216,8 +216,8 @@ QString Mtp3SummaryDialog::summaryToHtml
         QString bytes_s_str = n_a;
 
         for (size_t stat_idx = 0; stat_idx < mtp3_num_used; stat_idx++) {
-            si_msus += mtp3_stat[stat_idx].mtp3_si_code[si_code].num_msus;
-            si_bytes += mtp3_stat[stat_idx].mtp3_si_code[si_code].size;
+            si_msus += mtp3_stat[stat_idx].mtp3_si_code[ws_si_code].num_msus;
+            si_bytes += mtp3_stat[stat_idx].mtp3_si_code[ws_si_code].size;
         }
         total_msus += si_msus;
         total_bytes += si_bytes;
@@ -232,7 +232,7 @@ QString Mtp3SummaryDialog::summaryToHtml
         }
 
         out << table_row_begin
-            << table_data_tmpl.arg(mtp3_service_indicator_code_short_vals[si_code].strptr)
+            << table_data_tmpl.arg(mtp3_service_indicator_code_short_vals[ws_si_code].strptr)
             << table_data_tmpl.arg(si_msus)
             << table_data_tmpl.arg(msus_s_str)
             << table_data_tmpl.arg(si_bytes)
