$NetBSD: patch-libcassandra_keyspace__factory.cc,v 1.1 2013/05/30 15:36:29 joerg Exp $

--- libcassandra/keyspace_factory.cc.orig	2013-05-30 11:03:36.000000000 +0000
+++ libcassandra/keyspace_factory.cc
@@ -34,6 +34,16 @@ KeyspaceFactory::KeyspaceFactory() {}
 KeyspaceFactory::~KeyspaceFactory() {}
 
 
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+std::shared_ptr<Keyspace> KeyspaceFactory::create(Cassandra *client,
+                                                  const string &name,
+                                                  const map< string, map<string, string> > &descrip,
+                                                  ConsistencyLevel level)
+{
+  std::shared_ptr<Keyspace> ret(new Keyspace(client, name, descrip, level));
+  return ret;
+}
+#else
 tr1::shared_ptr<Keyspace> KeyspaceFactory::create(Cassandra *client,
                                                   const string &name,
                                                   const map< string, map<string, string> > &descrip,
@@ -42,4 +52,4 @@ tr1::shared_ptr<Keyspace> KeyspaceFactor
   tr1::shared_ptr<Keyspace> ret(new Keyspace(client, name, descrip, level));
   return ret;
 }
-
+#endif
\ No newline at end of file
