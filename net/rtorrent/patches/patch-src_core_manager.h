$NetBSD: patch-src_core_manager.h,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/core/manager.h.orig	2013-05-03 23:23:20.000000000 +0000
+++ src/core/manager.h
@@ -118,10 +118,12 @@ public:
 
   void                handshake_log(const sockaddr* sa, int msg, int err, const torrent::HashString* hash);
 
-  static const int create_start    = 0x1;
-  static const int create_tied     = 0x2;
-  static const int create_quiet    = 0x4;
-  static const int create_raw_data = 0x8;
+  enum {
+    create_start    = 0x1,
+    create_tied     = 0x2,
+    create_quiet    = 0x4,
+    create_raw_data = 0x8
+  };
 
   typedef std::vector<std::string> command_list_type;
 
