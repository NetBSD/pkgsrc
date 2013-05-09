$NetBSD: patch-src_torrent_utils_log.h,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/torrent/utils/log.h.orig	2012-04-20 06:41:43.000000000 +0000
+++ src/torrent/utils/log.h
@@ -39,8 +39,17 @@
 
 #include <string>
 #include <vector>
+#if __cplusplus >= 201103L
+#include <array>
+#include <functional>
+using std::array;
+using std::function;
+#else
 #include <tr1/array>
 #include <tr1/functional>
+using std::tr1::array;
+using std::tr1::function;
+#endif
 #include <torrent/common.h>
 
 namespace torrent {
@@ -147,7 +156,7 @@ class DownloadInfo;
 class download_data;
 class log_buffer;
 
-typedef std::tr1::function<void (const char*, unsigned int, int)> log_slot;
+typedef function<void (const char*, unsigned int, int)> log_slot;
 typedef std::vector<std::pair<std::string, log_slot> >            log_output_list;
 
 class LIBTORRENT_EXPORT log_group {
@@ -185,7 +194,7 @@ private:
   log_slot*           m_last;
 };
 
-typedef std::tr1::array<log_group, LOG_GROUP_MAX_SIZE> log_group_list;
+typedef array<log_group, LOG_GROUP_MAX_SIZE> log_group_list;
 
 extern log_group_list  log_groups LIBTORRENT_EXPORT;
 extern log_output_list log_outputs LIBTORRENT_EXPORT;
