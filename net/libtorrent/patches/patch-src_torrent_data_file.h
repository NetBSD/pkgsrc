$NetBSD: patch-src_torrent_data_file.h,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/torrent/data/file.h.orig	2012-01-19 10:19:26.000000000 +0000
+++ src/torrent/data/file.h
@@ -48,14 +48,16 @@ public:
 
   typedef std::pair<uint32_t, uint32_t> range_type;
 
-  static const int flag_active             = (1 << 0);
-  static const int flag_create_queued      = (1 << 1);
-  static const int flag_resize_queued      = (1 << 2);
-  static const int flag_fallocate          = (1 << 3);
-  static const int flag_previously_created = (1 << 4);
-
-  static const int flag_prioritize_first   = (1 << 5);
-  static const int flag_prioritize_last    = (1 << 6);
+  enum {
+    flag_active             = (1 << 0),
+    flag_create_queued      = (1 << 1),
+    flag_resize_queued      = (1 << 2),
+    flag_fallocate          = (1 << 3),
+    flag_previously_created = (1 << 4),
+
+    flag_prioritize_first   = (1 << 5),
+    flag_prioritize_last    = (1 << 6)
+  };
 
   File();
   ~File();
