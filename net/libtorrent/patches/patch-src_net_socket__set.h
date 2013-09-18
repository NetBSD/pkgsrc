$NetBSD: patch-src_net_socket__set.h,v 1.3 2013/09/18 16:32:05 joerg Exp $

--- src/net/socket_set.h.orig	2012-01-19 10:19:26.000000000 +0000
+++ src/net/socket_set.h
@@ -53,12 +53,12 @@ namespace torrent {
 
 // Propably should rename to EventSet...
 
-class SocketSet : private std::vector<Event*, rak::cacheline_allocator<> > {
+class SocketSet : private std::vector<Event*, rak::cacheline_allocator<Event *> > {
 public:
   typedef uint32_t    size_type;
 
-  typedef std::vector<Event*, rak::cacheline_allocator<> > base_type;
-  typedef std::vector<size_type, rak::cacheline_allocator<> > Table;
+  typedef std::vector<Event*, rak::cacheline_allocator<Event *> > base_type;
+  typedef std::vector<size_type, rak::cacheline_allocator<size_type> > Table;
 
   static const size_type npos = static_cast<size_type>(-1);
 
