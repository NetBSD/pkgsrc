$NetBSD: patch-libcassandra_keyspace__factory.h,v 1.1 2013/05/30 15:36:29 joerg Exp $

--- libcassandra/keyspace_factory.h.orig	2013-05-30 10:36:25.000000000 +0000
+++ libcassandra/keyspace_factory.h
@@ -12,7 +12,11 @@
 
 #include <string>
 #include <map>
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+#include <memory>
+#else
 #include <tr1/memory>
+#endif
 
 namespace libcassandra
 {
@@ -31,10 +35,17 @@ public:
   /**
    * @return a shared ptr which points to a Keyspace class
    */
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+  std::shared_ptr<Keyspace> create(Cassandra *client,
+                                        const std::string &name,
+                                        const std::map< std::string, std::map<std::string, std::string> > &descrip,
+                                        org::apache::cassandra::ConsistencyLevel level);
+#else
   std::tr1::shared_ptr<Keyspace> create(Cassandra *client,
                                         const std::string &name,
                                         const std::map< std::string, std::map<std::string, std::string> > &descrip,
                                         org::apache::cassandra::ConsistencyLevel level);
+#endif
 
 };
 
