$NetBSD: patch-src_torrent_utils_thread__base.h,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/torrent/utils/thread_base.h.orig	2012-03-05 12:18:18.000000000 +0000
+++ src/torrent/utils/thread_base.h
@@ -41,7 +41,13 @@
 #include <sys/types.h>
 #include <torrent/common.h>
 #include <torrent/utils/signal_bitfield.h>
+#if __cplusplus >= 201103L
+#include <functional>
+using std::function;
+#else
 #include <tr1/functional>
+using std::tr1::function;
+#endif
 
 namespace torrent {
 
@@ -50,8 +56,8 @@ class Poll;
 class LIBTORRENT_EXPORT lt_cacheline_aligned thread_base {
 public:
   typedef void* (*pthread_func)(void*);
-  typedef std::tr1::function<void ()>     slot_void;
-  typedef std::tr1::function<uint64_t ()> slot_timer;
+  typedef function<void ()>     slot_void;
+  typedef function<uint64_t ()> slot_timer;
   typedef class signal_bitfield           signal_type;
 
   enum state_type {
