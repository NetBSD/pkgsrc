$NetBSD: patch-libcassandra_cassandra.h,v 1.2 2020/05/14 19:09:10 joerg Exp $

--- libcassandra/cassandra.h.orig	2010-10-10 00:59:23.000000000 +0000
+++ libcassandra/cassandra.h
@@ -14,7 +14,7 @@
 #include <vector>
 #include <set>
 #include <map>
-#include <tr1/memory>
+#include <memory>
 
 #include "libgenthrift/cassandra_types.h"
 
@@ -65,17 +65,17 @@ public:
   /**
    * @return the keyspace with the given name.
    */
-  std::tr1::shared_ptr<Keyspace> getKeyspace(const std::string &name);
+  std::shared_ptr<Keyspace> getKeyspace(const std::string &name);
 
   /**
    * @return the keyspace with the given name at the given consistency level.
    */
-  std::tr1::shared_ptr<Keyspace> getKeyspace(const std::string &name, org::apache::cassandra::ConsistencyLevel level);
+  std::shared_ptr<Keyspace> getKeyspace(const std::string &name, org::apache::cassandra::ConsistencyLevel level);
 
   /**
    * Remove the given keyspace.
    */
-  void removeKeyspace(std::tr1::shared_ptr<Keyspace> k);
+  void removeKeyspace(std::shared_ptr<Keyspace> k);
 
   /**
    * @return the target server cluster name.
@@ -128,7 +128,7 @@ private:
   std::string config_file;
   std::set<std::string> key_spaces;
   std::map<std::string, std::string> token_map;
-  std::map<std::string, std::tr1::shared_ptr<Keyspace> > keyspace_map;
+  std::map<std::string, std::shared_ptr<Keyspace> > keyspace_map;
 
   Cassandra(const Cassandra&);
   Cassandra &operator=(const Cassandra&);
