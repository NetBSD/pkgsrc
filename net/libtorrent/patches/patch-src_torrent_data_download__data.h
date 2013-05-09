$NetBSD: patch-src_torrent_data_download__data.h,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/torrent/data/download_data.h.orig	2012-02-19 09:28:55.000000000 +0000
+++ src/torrent/data/download_data.h
@@ -37,7 +37,13 @@
 #ifndef LIBTORRENT_DATA_DOWNLOAD_DATA_H
 #define LIBTORRENT_DATA_DOWNLOAD_DATA_H
 
+#if __cplusplus >= 201103L
+#include <functional>
+using std::function;
+#else
 #include <tr1/functional>
+using std::tr1::function;
+#endif
 
 #include <torrent/common.h>
 #include <torrent/bitfield.h>
@@ -57,7 +63,7 @@ public:
 
   typedef void (function_void)(void);
 
-  typedef std::tr1::function<function_void> slot_void;
+  typedef function<function_void> slot_void;
 
   download_data() : m_wanted_chunks(0) {}
 
