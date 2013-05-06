$NetBSD: patch-sql_handler.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/handler.cc.orig	2013-05-05 20:55:20.000000000 +0000
+++ sql/handler.cc
@@ -5722,7 +5722,7 @@ handler::multi_range_read_init(RANGE_SEQ
   DBUG_ENTER("handler::multi_range_read_init");
   mrr_iter= seq_funcs->init(seq_init_param, n_ranges, mode);
   mrr_funcs= *seq_funcs;
-  mrr_is_output_sorted= test(mode & HA_MRR_SORTED);
+  mrr_is_output_sorted= my_test(mode & HA_MRR_SORTED);
   mrr_have_range= FALSE;
   DBUG_RETURN(0);
 }
@@ -5778,7 +5778,7 @@ scan_it_again:
                                  &mrr_cur_range.start_key : 0,
                                mrr_cur_range.end_key.keypart_map ?
                                  &mrr_cur_range.end_key : 0,
-                               test(mrr_cur_range.range_flag & EQ_RANGE),
+                               my_test(mrr_cur_range.range_flag & EQ_RANGE),
                                mrr_is_output_sorted);
       if (result != HA_ERR_END_OF_FILE)
         break;
@@ -5875,7 +5875,7 @@ int DsMrr_impl::dsmrr_init(handler *h_ar
 
   rowids_buf= buf->buffer;
 
-  is_mrr_assoc= !test(mode & HA_MRR_NO_ASSOCIATION);
+  is_mrr_assoc= !my_test(mode & HA_MRR_NO_ASSOCIATION);
 
   if (is_mrr_assoc)
     status_var_increment(table->in_use->status_var.ha_multi_range_read_init_count);
@@ -6113,7 +6113,7 @@ int DsMrr_impl::dsmrr_fill_buffer()
 
   if (res && res != HA_ERR_END_OF_FILE)
     DBUG_RETURN(res); 
-  dsmrr_eof= test(res == HA_ERR_END_OF_FILE);
+  dsmrr_eof= my_test(res == HA_ERR_END_OF_FILE);
 
   /* Sort the buffer contents by rowid */
   uint elem_size= h->ref_length + (int)is_mrr_assoc * sizeof(void*);
@@ -6166,7 +6166,7 @@ int DsMrr_impl::dsmrr_next(char **range_
     if (is_mrr_assoc)
       memcpy(&cur_range_info, rowids_buf_cur + h->ref_length, sizeof(uchar**));
 
-    rowids_buf_cur += h->ref_length + sizeof(void*) * test(is_mrr_assoc);
+    rowids_buf_cur += h->ref_length + sizeof(void*) * my_test(is_mrr_assoc);
     if (h2->mrr_funcs.skip_record &&
 	h2->mrr_funcs.skip_record(h2->mrr_iter, (char *) cur_range_info, rowid))
       continue;
@@ -6388,7 +6388,7 @@ bool DsMrr_impl::get_disk_sweep_mrr_cost
   double index_read_cost;
 
   const uint elem_size= h->ref_length + 
-                        sizeof(void*) * (!test(flags & HA_MRR_NO_ASSOCIATION));
+                        sizeof(void*) * (!my_test(flags & HA_MRR_NO_ASSOCIATION));
   const ha_rows max_buff_entries= *buffer_size / elem_size;
 
   if (!max_buff_entries)
