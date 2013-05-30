$NetBSD: patch-libcassandra_cassandra__factory.cc,v 1.1 2013/05/30 15:36:29 joerg Exp $

--- libcassandra/cassandra_factory.cc.orig	2013-05-30 10:34:39.000000000 +0000
+++ libcassandra/cassandra_factory.cc
@@ -63,17 +63,17 @@ CassandraFactory::CassandraFactory(const
 CassandraFactory::~CassandraFactory() {}
 
 
-tr1::shared_ptr<Cassandra> CassandraFactory::create()
+std::shared_ptr<Cassandra> CassandraFactory::create()
 {
   /* Default is Buffered Transport */
   return create(false);
 }
 
 
-tr1::shared_ptr<Cassandra> CassandraFactory::create(bool framed_transport)
+std::shared_ptr<Cassandra> CassandraFactory::create(bool framed_transport)
 {
   CassandraClient *thrift_client= createThriftClient(host, port, framed_transport);
-  tr1::shared_ptr<Cassandra> ret(new Cassandra(thrift_client, host, port));
+  std::shared_ptr<Cassandra> ret(new Cassandra(thrift_client, host, port));
   return ret;
 }
 
