$NetBSD: patch-src_torrent_utils_signal__bitfield.h,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/torrent/utils/signal_bitfield.h.orig	2012-04-20 06:41:43.000000000 +0000
+++ src/torrent/utils/signal_bitfield.h
@@ -37,7 +37,13 @@
 #ifndef LIBTORRENT_UTILS_SIGNAL_BITFIELD_H
 #define LIBTORRENT_UTILS_SIGNAL_BITFIELD_H
 
+#if __cplusplus >= 201103L
+#include <functional>
+using std::function;
+#else
 #include <tr1/functional>
+using std::tr1::function;
+#endif
 #include <torrent/common.h>
 
 namespace torrent {
@@ -45,7 +51,7 @@ namespace torrent {
 class LIBTORRENT_EXPORT lt_cacheline_aligned signal_bitfield {
 public:
   typedef uint32_t                    bitfield_type;
-  typedef std::tr1::function<void ()> slot_type;
+  typedef function<void ()> slot_type;
   
   static const unsigned int max_size = 32;
 
