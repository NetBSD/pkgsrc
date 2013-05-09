$NetBSD: patch-src_torrent_download_choke__queue.h,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/torrent/download/choke_queue.h.orig	2012-04-20 06:41:42.000000000 +0000
+++ src/torrent/download/choke_queue.h
@@ -42,7 +42,13 @@
 #include <list>
 #include <vector>
 #include <inttypes.h>
+#if __cplusplus >= 201103L
+#include <functional>
+using std::function;
+#else
 #include <tr1/functional>
+using std::tr1::function;
+#endif
 #include <torrent/download/group_entry.h>
 
 namespace torrent {
@@ -66,9 +72,9 @@ struct group_stats {
 
 class LIBTORRENT_EXPORT choke_queue {
 public:
-  typedef std::tr1::function<void (int)>                         slot_unchoke;
-  typedef std::tr1::function<int ()>                             slot_can_unchoke;
-  typedef std::tr1::function<bool (PeerConnectionBase*, bool)>   slot_connection;
+  typedef function<void (int)>                         slot_unchoke;
+  typedef function<int ()>                             slot_can_unchoke;
+  typedef function<bool (PeerConnectionBase*, bool)>   slot_connection;
 
   typedef std::vector<weighted_connection>                       container_type;
   typedef container_type::value_type                             value_type;
