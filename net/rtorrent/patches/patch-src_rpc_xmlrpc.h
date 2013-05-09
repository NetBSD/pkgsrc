$NetBSD: patch-src_rpc_xmlrpc.h,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/rpc/xmlrpc.h.orig	2013-05-03 22:41:35.000000000 +0000
+++ src/rpc/xmlrpc.h
@@ -37,7 +37,12 @@
 #ifndef RTORRENT_RPC_XMLRPC_H
 #define RTORRENT_RPC_XMLRPC_H
 
+#if __cplusplus >= 201103L
+using std::function;
+#else
 #include <tr1/functional>
+using std::tr1::function;
+#endif
 #include <torrent/hash_string.h>
 
 namespace core {
@@ -54,11 +59,11 @@ namespace rpc {
 
 class XmlRpc {
 public:
-  typedef std::tr1::function<core::Download* (const char*)>                 slot_download;
-  typedef std::tr1::function<torrent::File* (core::Download*, uint32_t)>    slot_file;
-  typedef std::tr1::function<torrent::Tracker* (core::Download*, uint32_t)> slot_tracker;
-  typedef std::tr1::function<torrent::Peer* (core::Download*, const torrent::HashString&)> slot_peer;
-  typedef std::tr1::function<bool (const char*, uint32_t)>                  slot_write;
+  typedef function<core::Download* (const char*)>                 slot_download;
+  typedef function<torrent::File* (core::Download*, uint32_t)>    slot_file;
+  typedef function<torrent::Tracker* (core::Download*, uint32_t)> slot_tracker;
+  typedef function<torrent::Peer* (core::Download*, const torrent::HashString&)> slot_peer;
+  typedef function<bool (const char*, uint32_t)>                  slot_write;
 
   static const int dialect_generic = 0;
   static const int dialect_i8      = 1;
