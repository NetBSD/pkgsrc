$NetBSD: patch-src_torrent_tracker__list.h,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/torrent/tracker_list.h.orig	2012-04-09 06:38:58.000000000 +0000
+++ src/torrent/tracker_list.h
@@ -41,7 +41,13 @@
 #include <string>
 #include <vector>
 #include <torrent/common.h>
+#if __cplusplus >= 201103L
+#include <functional>
+using std::function;
+#else
 #include <tr1/functional>
+using std::tr1::function;
+#endif
 
 namespace torrent {
 
@@ -64,9 +70,9 @@ public:
   typedef std::vector<Tracker*> base_type;
   typedef AddressList           address_list;
 
-  typedef std::tr1::function<void (Tracker*)>                     slot_tracker;
-  typedef std::tr1::function<void (Tracker*, const std::string&)> slot_string;
-  typedef std::tr1::function<uint32_t (Tracker*, AddressList*)>   slot_address_list;
+  typedef function<void (Tracker*)>                     slot_tracker;
+  typedef function<void (Tracker*, const std::string&)> slot_string;
+  typedef function<uint32_t (Tracker*, AddressList*)>   slot_address_list;
 
   using base_type::value_type;
 
