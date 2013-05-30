$NetBSD: patch-libcassandra_cassandra.h,v 1.1 2013/05/30 15:36:29 joerg Exp $

--- libcassandra/cassandra.h.orig	2013-05-30 10:29:32.000000000 +0000
+++ libcassandra/cassandra.h
@@ -14,7 +14,11 @@
 #include <vector>
 #include <set>
 #include <map>
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <memory>
+#else
 #include <tr1/memory>
+#endif
 
 #include "libgenthrift/cassandra_types.h"
 
@@ -65,17 +69,29 @@ public:
   /**
    * @return the keyspace with the given name.
    */
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+  std::shared_ptr<Keyspace> getKeyspace(const std::string &name);
+#else
   std::tr1::shared_ptr<Keyspace> getKeyspace(const std::string &name);
+#endif
 
   /**
    * @return the keyspace with the given name at the given consistency level.
    */
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+  std::shared_ptr<Keyspace> getKeyspace(const std::string &name, org::apache::cassandra::ConsistencyLevel level);
+#else
   std::tr1::shared_ptr<Keyspace> getKeyspace(const std::string &name, org::apache::cassandra::ConsistencyLevel level);
+#endif
 
   /**
    * Remove the given keyspace.
    */
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+  void removeKeyspace(std::shared_ptr<Keyspace> k);
+#else
   void removeKeyspace(std::tr1::shared_ptr<Keyspace> k);
+#endif
 
   /**
    * @return the target server cluster name.
@@ -128,7 +144,11 @@ private:
   std::string config_file;
   std::set<std::string> key_spaces;
   std::map<std::string, std::string> token_map;
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+  std::map<std::string, std::shared_ptr<Keyspace> > keyspace_map;
+#else
   std::map<std::string, std::tr1::shared_ptr<Keyspace> > keyspace_map;
+#endif
 
   Cassandra(const Cassandra&);
   Cassandra &operator=(const Cassandra&);
