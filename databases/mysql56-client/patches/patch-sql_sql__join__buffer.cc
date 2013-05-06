$NetBSD: patch-sql_sql__join__buffer.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/sql_join_buffer.cc.orig	2013-05-05 20:56:04.000000000 +0000
+++ sql/sql_join_buffer.cc
@@ -184,8 +184,8 @@ void JOIN_CACHE::calc_record_fields()
   for ( ; tab < join_tab ; tab++)
   {	    
     calc_used_field_length(join->thd, tab);
-    flag_fields+= test(tab->used_null_fields || tab->used_uneven_bit_fields);
-    flag_fields+= test(tab->table->maybe_null);
+    flag_fields+= my_test(tab->used_null_fields || tab->used_uneven_bit_fields);
+    flag_fields+= my_test(tab->table->maybe_null);
     fields+= tab->used_fields;
     blobs+= tab->used_blobs;
 
@@ -1350,7 +1350,7 @@ void JOIN_CACHE::get_record_by_pos(uchar
 bool JOIN_CACHE::get_match_flag_by_pos(uchar *rec_ptr)
 {
   if (with_match_flag)
-    return test(*rec_ptr);
+    return my_test(*rec_ptr);
   if (prev_cache)
   {
     uchar *prev_rec_ptr= prev_cache->get_rec_ref(rec_ptr);
@@ -1593,7 +1593,7 @@ bool JOIN_CACHE::skip_record_if_match()
   if (prev_cache)
     offset+= prev_cache->get_size_of_rec_offset();
   /* Check whether the match flag is on */
-  if (test(*(pos+offset)))
+  if (my_test(*(pos+offset)))
   {
     pos+= size_of_rec_len + get_rec_length(pos);
     return TRUE;
@@ -1886,7 +1886,7 @@ enum_nested_loop_state JOIN_CACHE_BNL::j
         reset_cache(false);
 
         /* Read each record from the join buffer and look for matches */
-        for (cnt= records - test(skip_last) ; cnt; cnt--)
+        for (cnt= records - my_test(skip_last) ; cnt; cnt--)
         { 
           /* 
             If only the first match is needed and it has been already found for
@@ -2131,7 +2131,7 @@ enum_nested_loop_state JOIN_CACHE::join_
   if (!records)
     DBUG_RETURN(NESTED_LOOP_OK);
   
-  cnt= records - (is_key_access() ? 0 : test(skip_last));
+  cnt= records - (is_key_access() ? 0 : my_test(skip_last));
 
   /* This function may be called only for inner tables of outer joins */ 
   DBUG_ASSERT(join_tab->first_inner);
