$NetBSD: patch-libcassandra_cassandra__factory.cc,v 1.2 2013/06/26 21:25:59 joerg Exp $

--- libcassandra/cassandra_factory.cc.orig	2013-05-30 10:34:39.000000000 +0000
+++ libcassandra/cassandra_factory.cc
@@ -63,17 +63,29 @@ CassandraFactory::CassandraFactory(const
 CassandraFactory::~CassandraFactory() {}
 
 
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+std::shared_ptr<Cassandra> CassandraFactory::create()
+#else
 tr1::shared_ptr<Cassandra> CassandraFactory::create()
+#endif
 {
   /* Default is Buffered Transport */
   return create(false);
 }
 
 
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+std::shared_ptr<Cassandra> CassandraFactory::create(bool framed_transport)
+#else
 tr1::shared_ptr<Cassandra> CassandraFactory::create(bool framed_transport)
+#endif
 {
   CassandraClient *thrift_client= createThriftClient(host, port, framed_transport);
+#if defined(_LIBCPP_VERSION) || __cplusplus >= 201103L
+  std::shared_ptr<Cassandra> ret(new Cassandra(thrift_client, host, port));
+#else
   tr1::shared_ptr<Cassandra> ret(new Cassandra(thrift_client, host, port));
+#endif
   return ret;
 }
 
