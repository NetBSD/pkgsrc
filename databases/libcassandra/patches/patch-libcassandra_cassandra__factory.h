$NetBSD: patch-libcassandra_cassandra__factory.h,v 1.1 2013/05/30 15:36:29 joerg Exp $

--- libcassandra/cassandra_factory.h.orig	2013-05-30 10:31:55.000000000 +0000
+++ libcassandra/cassandra_factory.h
@@ -12,7 +12,11 @@
 
 #include <string>
 #include <vector>
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <memory>
+#else
 #include <tr1/memory>
+#endif
 
 namespace org 
 { 
@@ -44,8 +48,13 @@ public:
   /**
    * @return a shared ptr which points to a Cassandra client
    */
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+  std::shared_ptr<Cassandra> create();
+  std::shared_ptr<Cassandra> create(bool framed_transport);
+#else
   std::tr1::shared_ptr<Cassandra> create();
   std::tr1::shared_ptr<Cassandra> create(bool framed_transport);
+#endif
 
   int getPort() const;
   const std::string &getHost() const;
