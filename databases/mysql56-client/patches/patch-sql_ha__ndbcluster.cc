$NetBSD: patch-sql_ha__ndbcluster.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- sql/ha_ndbcluster.cc.orig	2013-05-05 20:55:16.000000000 +0000
+++ sql/ha_ndbcluster.cc
@@ -2807,7 +2807,7 @@ int ha_ndbcluster::open_indexes(THD *thd
     if (check_index_fields_not_null(key_info))
       m_index[i].null_in_unique_index= TRUE;
 
-    if (error == 0 && test(index_flags(i, 0, 0) & HA_READ_RANGE))
+    if (error == 0 && my_test(index_flags(i, 0, 0) & HA_READ_RANGE))
       btree_keys.set_bit(i);
   }
 
