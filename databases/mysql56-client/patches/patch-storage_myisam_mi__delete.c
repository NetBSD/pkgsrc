$NetBSD: patch-storage_myisam_mi__delete.c,v 1.1 2013/04/29 21:16:57 joerg Exp $

--- storage/myisam/mi_delete.c.orig	2013-04-28 14:00:47.000000000 +0000
+++ storage/myisam/mi_delete.c
@@ -352,7 +352,7 @@ static int d_search(register MI_INFO *in
 	DBUG_RETURN(-1);
       }
       /* Page will be update later if we return 1 */
-      DBUG_RETURN(test(length <= (info->quick_mode ? MI_MIN_KEYBLOCK_LENGTH :
+      DBUG_RETURN(my_test(length <= (info->quick_mode ? MI_MIN_KEYBLOCK_LENGTH :
 				  (uint) keyinfo->underflow_block_length)));
     }
     save_flag=1;
