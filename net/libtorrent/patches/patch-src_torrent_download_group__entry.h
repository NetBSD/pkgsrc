$NetBSD: patch-src_torrent_download_group__entry.h,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/torrent/download/group_entry.h.orig	2012-01-19 10:19:26.000000000 +0000
+++ src/torrent/download/group_entry.h
@@ -39,7 +39,17 @@
 
 #include <algorithm>
 #include <vector>
+#if __cplusplus >= 201103L
+#include <functional>
+using std::function;
+using std::bind;
+#define STD_PLACEHOLDERS std::placeholders
+#else
 #include <tr1/functional>
+using std::tr1::bind;
+#define STD_PLACEHOLDERS std::tr1::placeholders
+using std::tr1::function;
+#endif
 #include <torrent/common.h>
 #include <torrent/exceptions.h>
 
@@ -104,7 +114,7 @@ private:
 
 inline void group_entry::connection_unchoked(PeerConnectionBase* pcb) {
   container_type::iterator itr = std::find_if(m_unchoked.begin(), m_unchoked.end(),
-                                              std::tr1::bind(&weighted_connection::operator==, std::tr1::placeholders::_1, pcb));
+                                              bind(&weighted_connection::operator==, STD_PLACEHOLDERS::_1, pcb));
 
   if (itr != m_unchoked.end()) throw internal_error("group_entry::connection_unchoked(pcb) failed.");
 
@@ -113,7 +123,7 @@ inline void group_entry::connection_unch
 
 inline void group_entry::connection_queued(PeerConnectionBase* pcb) {
   container_type::iterator itr = std::find_if(m_queued.begin(), m_queued.end(),
-                                              std::tr1::bind(&weighted_connection::operator==, std::tr1::placeholders::_1, pcb));
+                                              bind(&weighted_connection::operator==, STD_PLACEHOLDERS::_1, pcb));
 
   if (itr != m_queued.end()) throw internal_error("group_entry::connection_queued(pcb) failed.");
 
@@ -123,7 +133,7 @@ inline void group_entry::connection_queu
 inline void
 group_entry::connection_choked(PeerConnectionBase* pcb) {
   container_type::iterator itr = std::find_if(m_unchoked.begin(), m_unchoked.end(),
-                                              std::tr1::bind(&weighted_connection::operator==, std::tr1::placeholders::_1, pcb));
+                                              bind(&weighted_connection::operator==, STD_PLACEHOLDERS::_1, pcb));
 
   if (itr == m_unchoked.end()) throw internal_error("group_entry::connection_choked(pcb) failed.");
 
@@ -134,7 +144,7 @@ group_entry::connection_choked(PeerConne
 inline void
 group_entry::connection_unqueued(PeerConnectionBase* pcb) {
   container_type::iterator itr = std::find_if(m_queued.begin(), m_queued.end(),
-                                              std::tr1::bind(&weighted_connection::operator==, std::tr1::placeholders::_1, pcb));
+                                              bind(&weighted_connection::operator==, STD_PLACEHOLDERS::_1, pcb));
 
   if (itr == m_queued.end()) throw internal_error("group_entry::connection_unqueued(pcb) failed.");
 
