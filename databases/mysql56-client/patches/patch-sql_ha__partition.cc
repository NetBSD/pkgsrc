$NetBSD: patch-sql_ha__partition.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/ha_partition.cc.orig	2013-05-05 20:55:18.000000000 +0000
+++ sql/ha_partition.cc
@@ -3192,7 +3192,7 @@ int ha_partition::open(const char *name,
   m_mode= mode;
   m_open_test_lock= test_if_locked;
   m_part_field_array= m_part_info->full_part_field_array;
-  if (get_from_handler_file(name, &table->mem_root, test(m_is_clone_of)))
+  if (get_from_handler_file(name, &table->mem_root, my_test(m_is_clone_of)))
     DBUG_RETURN(error);
   name_buffer_ptr= m_name_buffer_ptr;
   if (populate_partition_name_hash())
@@ -5480,7 +5480,7 @@ int ha_partition::read_range_first(const
     m_start_key.key= NULL;
 
   m_index_scan_type= partition_read_range;
-  error= common_index_read(m_rec0, test(start_key));
+  error= common_index_read(m_rec0, my_test(start_key));
   DBUG_RETURN(error);
 }
 
@@ -7480,7 +7480,7 @@ uint32 ha_partition::calculate_key_hash_
   ulong nr1= 1;
   ulong nr2= 4;
   bool use_51_hash;
-  use_51_hash= test((*field_array)->table->part_info->key_algorithm ==
+  use_51_hash= my_test((*field_array)->table->part_info->key_algorithm ==
                     partition_info::KEY_ALGORITHM_51);
 
   do
