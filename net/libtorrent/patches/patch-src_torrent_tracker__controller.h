$NetBSD: patch-src_torrent_tracker__controller.h,v 1.3 2013/09/18 16:32:05 joerg Exp $

--- src/torrent/tracker_controller.h.orig	2012-03-19 11:36:45.000000000 +0000
+++ src/torrent/tracker_controller.h
@@ -38,7 +38,13 @@
 #define LIBTORRENT_TRACKER_CONTROLLER_H
 
 #include <string>
+#if __cplusplus >= 201103L
+#include <functional>
+using std::function;
+#else
 #include <tr1/functional>
+using std::tr1::function;
+#endif
 #include <torrent/common.h>
 #include <torrent/tracker.h>
 
@@ -55,10 +61,10 @@ class LIBTORRENT_EXPORT TrackerControlle
 public:
   typedef AddressList address_list;
 
-  typedef std::tr1::function<void (void)>               slot_void;
-  typedef std::tr1::function<void (const std::string&)> slot_string;
-  typedef std::tr1::function<uint32_t (AddressList*)>   slot_address_list;
-  typedef std::tr1::function<void (Tracker*)>           slot_tracker;
+  typedef function<void (void)>               slot_void;
+  typedef function<void (const std::string&)> slot_string;
+  typedef function<uint32_t (AddressList*)>   slot_address_list;
+  typedef function<void (Tracker*)>           slot_tracker;
 
   static const int flag_send_update      = 0x1;
   static const int flag_send_completed   = 0x2;
