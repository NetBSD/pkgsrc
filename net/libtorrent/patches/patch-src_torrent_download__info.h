$NetBSD: patch-src_torrent_download__info.h,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/torrent/download_info.h.orig	2012-04-09 06:38:58.000000000 +0000
+++ src/torrent/download_info.h
@@ -40,7 +40,13 @@
 #include <list>
 #include <string>
 #include <inttypes.h>
+#if __cplusplus >= 201103L
+#include <functional>
+using std::function;
+#else
 #include <tr1/functional>
+using std::tr1::function;
+#endif
 
 #include <torrent/rate.h>
 #include <torrent/hash_string.h>
@@ -54,13 +60,13 @@ class DownloadMain;
 
 class DownloadInfo {
 public:
-  typedef std::tr1::function<uint64_t ()>                              slot_stat_type;
-  typedef std::tr1::function<void (uint32_t)>                          slot_chunk_type;
+  typedef function<uint64_t ()>                              slot_stat_type;
+  typedef function<void (uint32_t)>                          slot_chunk_type;
 
-  typedef std::list<std::tr1::function<void ()> >                      signal_void_type;
-  typedef std::list<std::tr1::function<void (const std::string&)> >    signal_string_type;
+  typedef std::list<function<void ()> >                      signal_void_type;
+  typedef std::list<function<void (const std::string&)> >    signal_string_type;
   typedef std::list<slot_chunk_type>                                   signal_chunk_type;
-  typedef std::list<std::tr1::function<void (const std::string&, const char*, size_t)> > signal_dump_type;
+  typedef std::list<function<void (const std::string&, const char*, size_t)> > signal_dump_type;
 
   enum State {
     NONE,
@@ -69,17 +75,19 @@ public:
     STOPPED
   };
 
-  static const int flag_open                = (1 << 0);
-  static const int flag_active              = (1 << 1);
-  static const int flag_compact             = (1 << 2);
-  static const int flag_accepting_new_peers = (1 << 3);
-  static const int flag_accepting_seeders   = (1 << 4); // Only used during leeching.
-  static const int flag_private             = (1 << 5);
-  static const int flag_meta_download       = (1 << 6);
-  static const int flag_pex_enabled         = (1 << 7);
-  static const int flag_pex_active          = (1 << 8);
+  enum {
+    flag_open                = (1 << 0),
+    flag_active              = (1 << 1),
+    flag_compact             = (1 << 2),
+    flag_accepting_new_peers = (1 << 3),
+    flag_accepting_seeders   = (1 << 4), // Only used during leeching.
+    flag_private             = (1 << 5),
+    flag_meta_download       = (1 << 6),
+    flag_pex_enabled         = (1 << 7),
+    flag_pex_active          = (1 << 8),
 
-  static const int public_flags = flag_accepting_seeders;
+    public_flags = flag_accepting_seeders
+  };
 
   static const uint32_t unlimited = ~uint32_t();
 
