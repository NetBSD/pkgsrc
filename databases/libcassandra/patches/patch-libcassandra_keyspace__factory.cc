$NetBSD: patch-libcassandra_keyspace__factory.cc,v 1.2 2020/05/14 19:09:10 joerg Exp $

--- libcassandra/keyspace_factory.cc.orig	2010-10-10 00:59:23.000000000 +0000
+++ libcassandra/keyspace_factory.cc
@@ -34,12 +34,11 @@ KeyspaceFactory::KeyspaceFactory() {}
 KeyspaceFactory::~KeyspaceFactory() {}
 
 
-tr1::shared_ptr<Keyspace> KeyspaceFactory::create(Cassandra *client,
+std::shared_ptr<Keyspace> KeyspaceFactory::create(Cassandra *client,
                                                   const string &name,
                                                   const map< string, map<string, string> > &descrip,
                                                   ConsistencyLevel level)
 {
-  tr1::shared_ptr<Keyspace> ret(new Keyspace(client, name, descrip, level));
+  std::shared_ptr<Keyspace> ret(new Keyspace(client, name, descrip, level));
   return ret;
 }
-
