$NetBSD: patch-src_torrent_peer_connection__list.h,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/torrent/peer/connection_list.h.orig	2012-04-09 06:38:58.000000000 +0000
+++ src/torrent/peer/connection_list.h
@@ -39,7 +39,13 @@
 
 #include <list>
 #include <vector>
+#if __cplusplus >= 201103L
+#include <functional>
+using std::function;
+#else
 #include <tr1/functional>
+using std::tr1::function;
+#endif
 #include <torrent/common.h>
 #include <torrent/hash_string.h>
 
@@ -66,7 +72,7 @@ public:
   typedef std::vector<Peer*>         base_type;
   typedef std::vector<HashString>    queue_type;
   typedef uint32_t                   size_type;
-  typedef std::tr1::function<void (Peer*)> slot_peer_type;
+  typedef function<void (Peer*)> slot_peer_type;
   typedef std::list<slot_peer_type>        signal_peer_type;
 
   typedef PeerConnectionBase* (*slot_new_conn_type)(bool encrypted);
@@ -90,10 +96,12 @@ public:
   using base_type::rend;
   
   // Make sure any change here match PeerList's flags.
-  static const int disconnect_available = (1 << 0);
-  static const int disconnect_quick     = (1 << 1);
-  static const int disconnect_unwanted  = (1 << 2);
-  static const int disconnect_delayed   = (1 << 3);
+  enum {
+    disconnect_available = (1 << 0),
+    disconnect_quick     = (1 << 1),
+    disconnect_unwanted  = (1 << 2),
+    disconnect_delayed   = (1 << 3)
+  };
 
   ConnectionList(DownloadMain* download);
 
