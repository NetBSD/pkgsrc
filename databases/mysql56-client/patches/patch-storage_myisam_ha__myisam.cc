$NetBSD: patch-storage_myisam_ha__myisam.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- storage/myisam/ha_myisam.cc.orig	2013-05-05 21:01:47.000000000 +0000
+++ storage/myisam/ha_myisam.cc
@@ -464,8 +464,8 @@ int check_definition(MI_KEYDEF *t1_keyin
     {
        DBUG_PRINT("error", ("Key %d has different definition", i));
        DBUG_PRINT("error", ("t1_fulltext= %d, t2_fulltext=%d",
-                            test(t1_keyinfo[i].flag & HA_FULLTEXT),
-                            test(t2_keyinfo[i].flag & HA_FULLTEXT)));
+                            my_test(t1_keyinfo[i].flag & HA_FULLTEXT),
+                            my_test(t2_keyinfo[i].flag & HA_FULLTEXT)));
        DBUG_RETURN(1);
     }
     if (t1_keyinfo[i].flag & HA_SPATIAL && t2_keyinfo[i].flag & HA_SPATIAL)
@@ -475,8 +475,8 @@ int check_definition(MI_KEYDEF *t1_keyin
     {
        DBUG_PRINT("error", ("Key %d has different definition", i));
        DBUG_PRINT("error", ("t1_spatial= %d, t2_spatial=%d",
-                            test(t1_keyinfo[i].flag & HA_SPATIAL),
-                            test(t2_keyinfo[i].flag & HA_SPATIAL)));
+                            my_test(t1_keyinfo[i].flag & HA_SPATIAL),
+                            my_test(t2_keyinfo[i].flag & HA_SPATIAL)));
        DBUG_RETURN(1);
     }
     if ((!mysql_40_compat &&
@@ -1067,7 +1067,7 @@ int ha_myisam::repair(THD *thd, MI_CHECK
 			share->state.key_map);
     uint testflag=param.testflag;
 #ifdef HAVE_MMAP
-    bool remap= test(share->file_map);
+    bool remap= my_test(share->file_map);
     /*
       mi_repair*() functions family use file I/O even if memory
       mapping is available.
@@ -1609,7 +1609,7 @@ ICP_RESULT index_cond_func_myisam(void *
   if (h->end_range && h->compare_key_icp(h->end_range) > 0)
     return ICP_OUT_OF_RANGE; /* caller should return HA_ERR_END_OF_FILE already */
 
-  return (ICP_RESULT) test(h->pushed_idx_cond->val_int());
+  return (ICP_RESULT) my_test(h->pushed_idx_cond->val_int());
 }
 
 C_MODE_END
