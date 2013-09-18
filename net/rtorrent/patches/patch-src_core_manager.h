$NetBSD: patch-src_core_manager.h,v 1.3 2013/09/18 16:33:08 joerg Exp $

--- src/core/manager.h.orig	2012-03-13 12:10:49.000000000 +0000
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
 
