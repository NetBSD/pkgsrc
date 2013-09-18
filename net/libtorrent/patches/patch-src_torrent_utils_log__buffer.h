$NetBSD: patch-src_torrent_utils_log__buffer.h,v 1.3 2013/09/18 16:32:05 joerg Exp $

--- src/torrent/utils/log_buffer.h.orig	2012-03-13 12:09:16.000000000 +0000
+++ src/torrent/utils/log_buffer.h
@@ -40,7 +40,13 @@
 #include <string>
 #include <deque>
 #include <pthread.h>
+#if __cplusplus >= 201103L
+#include <functional>
+using std::function;
+#else
 #include <tr1/functional>
+using std::tr1::function;
+#endif
 #include <torrent/common.h>
 
 namespace torrent {
@@ -60,7 +66,7 @@ struct log_entry {
 class LIBTORRENT_EXPORT log_buffer : private std::deque<log_entry> {
 public:
   typedef std::deque<log_entry>       base_type;
-  typedef std::tr1::function<void ()> slot_void;
+  typedef function<void ()> slot_void;
 
   using base_type::iterator;
   using base_type::const_iterator;
