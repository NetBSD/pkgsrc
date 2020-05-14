$NetBSD: patch-libcassandra_keyspace__factory.h,v 1.2 2020/05/14 19:09:10 joerg Exp $

--- libcassandra/keyspace_factory.h.orig	2010-10-10 00:58:51.000000000 +0000
+++ libcassandra/keyspace_factory.h
@@ -12,7 +12,7 @@
 
 #include <string>
 #include <map>
-#include <tr1/memory>
+#include <memory>
 
 namespace libcassandra
 {
@@ -31,7 +31,7 @@ public:
   /**
    * @return a shared ptr which points to a Keyspace class
    */
-  std::tr1::shared_ptr<Keyspace> create(Cassandra *client,
+  std::shared_ptr<Keyspace> create(Cassandra *client,
                                         const std::string &name,
                                         const std::map< std::string, std::map<std::string, std::string> > &descrip,
                                         org::apache::cassandra::ConsistencyLevel level);
