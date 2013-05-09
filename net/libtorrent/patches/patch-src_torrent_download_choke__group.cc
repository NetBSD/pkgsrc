$NetBSD: patch-src_torrent_download_choke__group.cc,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/torrent/download/choke_group.cc.orig	2012-03-20 16:33:27.000000000 +0000
+++ src/torrent/download/choke_group.cc
@@ -37,7 +37,15 @@
 #include "config.h"
 
 #include <algorithm>
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+#define STD_PLACEHOLDERS std::placeholders
+#else
 #include <tr1/functional>
+using std::tr1::bind;
+#define STD_PLACEHOLDERS std::tr1::placeholders
+#endif
 
 #include "choke_group.h"
 #include "choke_queue.h"
@@ -48,8 +56,6 @@
 #include "torrent/exceptions.h"
 #include "download/download_main.h"
 
-namespace tr1 { using namespace std::tr1; }
-
 namespace torrent {
 
 choke_group::choke_group() :
@@ -61,14 +67,14 @@ uint64_t
 choke_group::up_rate() const {
   return
     std::for_each(m_first, m_last, 
-                  rak::accumulate((uint64_t)0, tr1::bind(&Rate::rate, tr1::bind(&resource_manager_entry::up_rate, tr1::placeholders::_1)))).result;
+                  rak::accumulate((uint64_t)0, bind(&Rate::rate, bind(&resource_manager_entry::up_rate, STD_PLACEHOLDERS::_1)))).result;
 }
 
 uint64_t
 choke_group::down_rate() const {
   return
     std::for_each(m_first, m_last, 
-                  rak::accumulate((uint64_t)0, tr1::bind(&Rate::rate, tr1::bind(&resource_manager_entry::down_rate, tr1::placeholders::_1)))).result;
+                  rak::accumulate((uint64_t)0, bind(&Rate::rate, bind(&resource_manager_entry::down_rate, STD_PLACEHOLDERS::_1)))).result;
 }
 
 }
