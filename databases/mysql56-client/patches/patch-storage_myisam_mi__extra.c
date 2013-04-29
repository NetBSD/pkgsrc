$NetBSD: patch-storage_myisam_mi__extra.c,v 1.1 2013/04/29 21:16:57 joerg Exp $

--- storage/myisam/mi_extra.c.orig	2013-04-28 14:00:41.000000000 +0000
+++ storage/myisam/mi_extra.c
@@ -55,7 +55,7 @@ int mi_extra(MI_INFO *info, enum ha_extr
     {
       reinit_io_cache(&info->rec_cache,READ_CACHE,0,
 		      (pbool) (info->lock_type != F_UNLCK),
-		      (pbool) test(info->update & HA_STATE_ROW_CHANGED)
+		      (pbool) my_test(info->update & HA_STATE_ROW_CHANGED)
 		      );
     }
     info->update= ((info->update & HA_STATE_CHANGED) | HA_STATE_NEXT_FOUND |
@@ -116,7 +116,7 @@ int mi_extra(MI_INFO *info, enum ha_extr
     {
       reinit_io_cache(&info->rec_cache,READ_CACHE,info->nextpos,
 		      (pbool) (info->lock_type != F_UNLCK),
-		      (pbool) test(info->update & HA_STATE_ROW_CHANGED));
+		      (pbool) my_test(info->update & HA_STATE_ROW_CHANGED));
       info->update&= ~HA_STATE_ROW_CHANGED;
       if (share->concurrent_insert)
 	info->rec_cache.end_of_file=info->state->data_file_length;
