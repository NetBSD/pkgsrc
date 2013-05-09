$NetBSD: patch-src_torrent_peer_client__list.cc,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/torrent/peer/client_list.cc.orig	2012-02-14 03:15:27.000000000 +0000
+++ src/torrent/peer/client_list.cc
@@ -38,7 +38,15 @@
 
 #include <algorithm>
 #include <rak/string_manip.h>
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+#define STD_PLACEHOLDERS std::placeholders
+#else
 #include <tr1/functional>
+using std::tr1::bind;
+#define STD_PLACEHOLDERS std::tr1::placeholders
+#endif
 
 #include "client_list.h"
 #include "exceptions.h"
@@ -227,7 +235,7 @@ ClientList::retrieve_id(ClientInfo* dest
     return false;
   }
 
-  const_iterator itr = std::find_if(begin() + 1, end(), std::tr1::bind(&ClientInfo::intersects, *dest, std::tr1::placeholders::_1));
+  const_iterator itr = std::find_if(begin() + 1, end(), bind(&ClientInfo::intersects, *dest, STD_PLACEHOLDERS::_1));
 
   if (itr == end())
     dest->set_info(begin()->info());
