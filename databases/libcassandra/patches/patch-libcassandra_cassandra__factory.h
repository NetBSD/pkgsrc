$NetBSD: patch-libcassandra_cassandra__factory.h,v 1.2 2020/05/14 19:09:10 joerg Exp $

--- libcassandra/cassandra_factory.h.orig	2010-10-10 00:59:23.000000000 +0000
+++ libcassandra/cassandra_factory.h
@@ -12,7 +12,7 @@
 
 #include <string>
 #include <vector>
-#include <tr1/memory>
+#include <memory>
 
 namespace org 
 { 
@@ -44,8 +44,8 @@ public:
   /**
    * @return a shared ptr which points to a Cassandra client
    */
-  std::tr1::shared_ptr<Cassandra> create();
-  std::tr1::shared_ptr<Cassandra> create(bool framed_transport);
+  std::shared_ptr<Cassandra> create();
+  std::shared_ptr<Cassandra> create(bool framed_transport);
 
   int getPort() const;
   const std::string &getHost() const;
