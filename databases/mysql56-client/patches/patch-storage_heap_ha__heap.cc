$NetBSD: patch-storage_heap_ha__heap.cc,v 1.1 2013/05/06 14:41:08 joerg Exp $

--- storage/heap/ha_heap.cc.orig	2013-04-05 12:27:17.000000000 +0000
+++ storage/heap/ha_heap.cc
@@ -97,7 +97,7 @@ const char **ha_heap::bas_ext() const
 
 int ha_heap::open(const char *name, int mode, uint test_if_locked)
 {
-  internal_table= test(test_if_locked & HA_OPEN_INTERNAL_TABLE);
+  internal_table= my_test(test_if_locked & HA_OPEN_INTERNAL_TABLE);
   if (internal_table || (!(file= heap_open(name, mode)) && my_errno == ENOENT))
   {
     HP_CREATE_INFO create_info;
@@ -113,7 +113,7 @@ int ha_heap::open(const char *name, int 
     if (rc)
       goto end;
 
-    implicit_emptied= test(created_new_share);
+    implicit_emptied= my_test(created_new_share);
     if (internal_table)
       file= heap_open_from_share(internal_share, mode);
     else
