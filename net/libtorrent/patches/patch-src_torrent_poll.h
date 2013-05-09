$NetBSD: patch-src_torrent_poll.h,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/torrent/poll.h.orig	2012-02-14 04:05:05.000000000 +0000
+++ src/torrent/poll.h
@@ -37,7 +37,13 @@
 #ifndef LIBTORRENT_TORRENT_POLL_H
 #define LIBTORRENT_TORRENT_POLL_H
 
+#if __cplusplus >= 201103L
+#include <functional>
+using std::function;
+#else
 #include <tr1/functional>
+using std::tr1::function;
+#endif
 #include <torrent/common.h>
 
 namespace torrent {
@@ -46,7 +52,7 @@ class Event;
 
 class LIBTORRENT_EXPORT Poll {
 public:
-  typedef std::tr1::function<Poll* ()> slot_poll;
+  typedef function<Poll* ()> slot_poll;
 
   static const int      poll_worker_thread     = 0x1;
   static const uint32_t flag_waive_global_lock = 0x1;
