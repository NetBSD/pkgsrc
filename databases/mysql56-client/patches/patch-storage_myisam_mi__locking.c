$NetBSD: patch-storage_myisam_mi__locking.c,v 1.1 2013/04/29 21:16:57 joerg Exp $

--- storage/myisam/mi_locking.c.orig	2013-04-28 14:00:39.000000000 +0000
+++ storage/myisam/mi_locking.c
@@ -567,5 +567,5 @@ int _mi_decrement_open_count(MI_INFO *in
     if (!lock_error)
       lock_error=mi_lock_database(info,old_lock);
   }
-  return test(lock_error || write_error);
+  return my_test(lock_error || write_error);
 }
